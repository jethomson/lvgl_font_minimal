#include "lv_font_minimal.h"

/**
 * Get the descriptor of a glyph
 * @param font          pointer to font
 * @param dsc_out       store the result descriptor here
 * @param letter        a UNICODE letter code
 * @param letter_next   the next letter after `letter`. Used for kerning
 * @return true: descriptor is successfully loaded into `dsc_out`.
 *         false: the letter was not found, no data is loaded to `dsc_out`
 */
bool lv_font_get_glyph_dsc(const lv_font_t * font_p, lv_font_glyph_dsc_t * dsc_out, uint32_t letter,
                           uint32_t letter_next)
{

    LV_ASSERT_NULL(font_p);
    LV_ASSERT_NULL(dsc_out);

#if LV_USE_FONT_PLACEHOLDER
    const lv_font_t * placeholder_font = NULL;
#endif

    const lv_font_t * f = font_p;

    dsc_out->resolved_font = NULL;

    while(f) {
        bool found = f->get_glyph_dsc(f, dsc_out, letter, f->kerning == LV_FONT_KERNING_NONE ? 0 : letter_next);
        if(found) {
            if(!dsc_out->is_placeholder) {
                dsc_out->resolved_font = f;
                return true;
            }
#if LV_USE_FONT_PLACEHOLDER
            else if(placeholder_font == NULL) {
                placeholder_font = f;
            }
#endif
        }
        f = f->fallback;
    }

#if LV_USE_FONT_PLACEHOLDER
    if(placeholder_font != NULL) {
        placeholder_font->get_glyph_dsc(placeholder_font, dsc_out, letter,
                                        placeholder_font->kerning == LV_FONT_KERNING_NONE ? 0 : letter_next);
        dsc_out->resolved_font = placeholder_font;
        return true;
    }
#endif

#if LV_USE_FONT_PLACEHOLDER
    dsc_out->box_w = font_p->line_height / 2;
    dsc_out->adv_w = dsc_out->box_w + 2;
#else
    dsc_out->box_w = 0;
    dsc_out->adv_w = 0;
#endif

    dsc_out->resolved_font = NULL;
    dsc_out->box_h = font_p->line_height;
    dsc_out->ofs_x = 0;
    dsc_out->ofs_y = 0;
    dsc_out->format = LV_FONT_GLYPH_FORMAT_A1;
    dsc_out->is_placeholder = true;

    return false;
}


/**
 * Used as `get_glyph_dsc` callback in lvgl's native font format if the font is uncompressed.
 * @param font pointer to font
 * @param dsc_out store the result descriptor here
 * @param unicode_letter a UNICODE letter code
 * @param unicode_letter_next the unicode letter succeeding the letter under test
 * @return true: descriptor is successfully loaded into `dsc_out`.
 *         false: the letter was not found, no data is loaded to `dsc_out`
 */
bool lv_font_get_glyph_dsc_fmt_txt(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter,
                                   uint32_t unicode_letter_next)
{
    //It fixes a strange compiler optimization issue: https://github.com/lvgl/lvgl/issues/4370
    bool is_tab = unicode_letter == '\t';
    if(is_tab) {
        unicode_letter = ' ';
    }
    lv_font_fmt_txt_dsc_t * fdsc = (lv_font_fmt_txt_dsc_t *)font->dsc;
    uint32_t gid = get_glyph_dsc_id(font, unicode_letter);
    if(!gid) return false;

    int8_t kvalue = 0;
    if(fdsc->kern_dsc) {
        uint32_t gid_next = get_glyph_dsc_id(font, unicode_letter_next);
        if(gid_next) {
            kvalue = get_kern_value(font, gid, gid_next);
        }
    }

    //Put together a glyph dsc
    const lv_font_fmt_txt_glyph_dsc_t * gdsc = &fdsc->glyph_dsc[gid];

    int32_t kv = ((int32_t)((int32_t)kvalue * fdsc->kern_scale) >> 4);

    uint32_t adv_w = gdsc->adv_w;
    if(is_tab) adv_w *= 2;

    adv_w += kv;
    adv_w  = (adv_w + (1 << 3)) >> 4;

    dsc_out->adv_w = adv_w;
    dsc_out->box_h = gdsc->box_h;
    dsc_out->box_w = gdsc->box_w;
    dsc_out->ofs_x = gdsc->ofs_x;
    dsc_out->ofs_y = gdsc->ofs_y;
    dsc_out->format = (uint8_t)fdsc->bpp;
    dsc_out->is_placeholder = false;
    dsc_out->gid.index = gid;

    if(is_tab) dsc_out->box_w = dsc_out->box_w * 2;

    return true;
}


static uint32_t get_glyph_dsc_id(const lv_font_t * font, uint32_t letter)
{
    if(letter == '\0') return 0;

    lv_font_fmt_txt_dsc_t * fdsc = (lv_font_fmt_txt_dsc_t *)font->dsc;

    uint16_t i;
    for(i = 0; i < fdsc->cmap_num; i++) {

        /*Relative code point*/
        uint32_t rcp = letter - fdsc->cmaps[i].range_start;
        if(rcp >= fdsc->cmaps[i].range_length) continue;
        uint32_t glyph_id = 0;
        if(fdsc->cmaps[i].type == LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY) {
            glyph_id = fdsc->cmaps[i].glyph_id_start + rcp;
        }
        else if(fdsc->cmaps[i].type == LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL) {
            const uint8_t * gid_ofs_8 = (const uint8_t *)fdsc->cmaps[i].glyph_id_ofs_list;
            glyph_id = fdsc->cmaps[i].glyph_id_start + gid_ofs_8[rcp];
        }
        else if(fdsc->cmaps[i].type == LV_FONT_FMT_TXT_CMAP_SPARSE_TINY) {
            uint16_t key = rcp;
            uint16_t * p = (uint16_t *)_lv_utils_bsearch(&key, fdsc->cmaps[i].unicode_list, fdsc->cmaps[i].list_length,
                                             sizeof(fdsc->cmaps[i].unicode_list[0]), unicode_list_compare);

            if(p) {
                lv_uintptr_t ofs = p - fdsc->cmaps[i].unicode_list;
                glyph_id = fdsc->cmaps[i].glyph_id_start + (uint32_t) ofs;
            }
        }
        else if(fdsc->cmaps[i].type == LV_FONT_FMT_TXT_CMAP_SPARSE_FULL) {
            uint16_t key = rcp;
            uint16_t * p = (uint16_t *)_lv_utils_bsearch(&key, fdsc->cmaps[i].unicode_list, fdsc->cmaps[i].list_length,
                                             sizeof(fdsc->cmaps[i].unicode_list[0]), unicode_list_compare);

            if(p) {
                lv_uintptr_t ofs = p - fdsc->cmaps[i].unicode_list;
                const uint16_t * gid_ofs_16 = (const uint16_t *)fdsc->cmaps[i].glyph_id_ofs_list;
                glyph_id = fdsc->cmaps[i].glyph_id_start + gid_ofs_16[ofs];
            }
        }

        return glyph_id;
    }

    return 0;

}


/** Code Comparator.
 *
 *  Compares the value of both input arguments.
 *
 *  @param[in]  pRef        Pointer to the reference.
 *  @param[in]  pElement    Pointer to the element to compare.
 *
 *  @return Result of comparison.
 *  @retval < 0   Reference is less than element.
 *  @retval = 0   Reference is equal to element.
 *  @retval > 0   Reference is greater than element.
 *
 */
static int32_t unicode_list_compare(const void * ref, const void * element)
{
    return ((int32_t)(*(uint16_t *)ref)) - ((int32_t)(*(uint16_t *)element));
}


static int8_t get_kern_value(const lv_font_t * font, uint32_t gid_left, uint32_t gid_right)
{
    lv_font_fmt_txt_dsc_t * fdsc = (lv_font_fmt_txt_dsc_t *)font->dsc;

    int8_t value = 0;

    if(fdsc->kern_classes == 0) {
        /*Kern pairs*/
        const lv_font_fmt_txt_kern_pair_t * kdsc = (const lv_font_fmt_txt_kern_pair_t *)fdsc->kern_dsc;
        if(kdsc->glyph_ids_size == 0) {
            /*Use binary search to find the kern value.
             *The pairs are ordered left_id first, then right_id secondly.*/
            const uint16_t * g_ids = (const uint16_t *)kdsc->glyph_ids;
            kern_pair_ref_t g_id_both = {gid_left, gid_right};
            uint16_t * kid_p = (uint16_t *)_lv_utils_bsearch(&g_id_both, g_ids, kdsc->pair_cnt, 2, kern_pair_8_compare);

            /*If the `g_id_both` were found get its index from the pointer*/
            if(kid_p) {
                lv_uintptr_t ofs = kid_p - g_ids;
                value = kdsc->values[ofs];
            }
        }
        else if(kdsc->glyph_ids_size == 1) {
            /*Use binary search to find the kern value.
             *The pairs are ordered left_id first, then right_id secondly.*/
            const uint32_t * g_ids = (const uint32_t *)kdsc->glyph_ids;
            kern_pair_ref_t g_id_both = {gid_left, gid_right};
            uint32_t * kid_p = (uint32_t *)_lv_utils_bsearch(&g_id_both, g_ids, kdsc->pair_cnt, 4, kern_pair_16_compare);

            /*If the `g_id_both` were found get its index from the pointer*/
            if(kid_p) {
                lv_uintptr_t ofs = kid_p - g_ids;
                value = kdsc->values[ofs];
            }

        }
        else {
            /*Invalid value*/
        }
    }
    else {
        /*Kern classes*/
        const lv_font_fmt_txt_kern_classes_t * kdsc = (const lv_font_fmt_txt_kern_classes_t *)fdsc->kern_dsc;
        uint8_t left_class = kdsc->left_class_mapping[gid_left];
        uint8_t right_class = kdsc->right_class_mapping[gid_right];

        /*If class = 0, kerning not exist for that glyph
         *else got the value form `class_pair_values` 2D array*/
        if(left_class > 0 && right_class > 0) {
            value = kdsc->class_pair_values[(left_class - 1) * kdsc->right_class_cnt + (right_class - 1)];
        }

    }
    return value;
}


void * _lv_utils_bsearch(const void * key, const void * base, uint32_t n, uint32_t size,
                         int32_t (*cmp)(const void * pRef, const void * pElement))
{
    const char * middle;
    int32_t c;

    for(middle = (char *)base; n != 0;) {
        middle += (n / 2) * size;
        if((c = (*cmp)(key, middle)) > 0) {
            n    = (n / 2) - ((n & 1) == 0);
            base = (middle += size);
        }
        else if(c < 0) {
            n /= 2;
            middle = (char *)base;
        }
        else {
            return (char *)middle;
        }
    }
    return NULL;
}


static int32_t kern_pair_8_compare(const void * ref, const void * element)
{
    const kern_pair_ref_t * ref8_p = (const kern_pair_ref_t *)ref;
    const uint8_t * element8_p = (const uint8_t *)element;

    /*If the MSB is different it will matter. If not return the diff. of the LSB*/
    if(ref8_p->gid_left != element8_p[0]) return (int32_t) ref8_p->gid_left - element8_p[0];
    else return (int32_t) ref8_p->gid_right - element8_p[1];

}


static int32_t kern_pair_16_compare(const void * ref, const void * element)
{
    const kern_pair_ref_t * ref16_p = (const kern_pair_ref_t *)ref;
    const uint16_t * element16_p = (const uint16_t *)element;

    /*If the MSB is different it will matter. If not return the diff. of the LSB*/
    if(ref16_p->gid_left != element16_p[0]) return (int32_t) ref16_p->gid_left - element16_p[0];
    else return (int32_t) ref16_p->gid_right - element16_p[1];
}






/**
 * Used as `get_glyph_bitmap` callback in lvgl's native font format if the font is uncompressed.
 * @param g_dsc         the glyph descriptor including which font to use, which supply the glyph_index and format.
 * @param draw_buf      a draw buffer that can be used to store the bitmap of the glyph, it's OK not to use it.
 * @return pointer to an A8 bitmap (not necessarily bitmap_out) or NULL if `unicode_letter` not found
 */
/*
const void * lv_font_get_bitmap_fmt_txt(lv_font_glyph_dsc_t * g_dsc, lv_draw_buf_t * draw_buf)
{
    // the following full definition of lv_font_get_bitmap_fmt_txt() is not needed if you only
    // ever want to pull 8 bpp characters from the font files.
    return NULL;
}
*/

/**
 * Used as `get_glyph_bitmap` callback in lvgl's native font format if the font is uncompressed.
 * @param g_dsc         the glyph descriptor including which font to use, which supply the glyph_index and format.
 * @param draw_buf      a draw buffer that can be used to store the bitmap of the glyph, it's OK not to use it.
 * @return pointer to an A8 bitmap (not necessarily bitmap_out) or NULL if `unicode_letter` not found
 */
const void * lv_font_get_bitmap_fmt_txt(lv_font_glyph_dsc_t * g_dsc, lv_draw_buf_t * draw_buf)
{
    //_cb(42); // example of how to print a number to serial for debugging
    const lv_font_t * font = g_dsc->resolved_font;
    uint8_t * bitmap_out = draw_buf->data;

    lv_font_fmt_txt_dsc_t * fdsc = (lv_font_fmt_txt_dsc_t *)font->dsc;
    uint32_t gid = g_dsc->gid.index;
    if(!gid) return NULL;

    const lv_font_fmt_txt_glyph_dsc_t * gdsc = &fdsc->glyph_dsc[gid];

    int32_t gsize = (int32_t) gdsc->box_w * gdsc->box_h;
    if(gsize == 0) return NULL;

    if(fdsc->bitmap_format == LV_FONT_FMT_TXT_PLAIN) {
        const uint8_t * bitmap_in = &fdsc->glyph_bitmap[gdsc->bitmap_index];
        uint8_t * bitmap_out_tmp = bitmap_out;
        int32_t i = 0;
        int32_t x, y;
        //uint32_t stride = lv_draw_buf_width_to_stride(gdsc->box_w, LV_COLOR_FORMAT_A8);
        uint32_t stride = gdsc->box_w;

        if(fdsc->bpp == 1) {
            for(y = 0; y < gdsc->box_h; y ++) {
                for(x = 0; x < gdsc->box_w; x++, i++) {
                    i = i & 0x7;
                    if(i == 0) bitmap_out_tmp[x] = (*bitmap_in) & 0x80 ? 0xff : 0x00;
                    else if(i == 1) bitmap_out_tmp[x] = (*bitmap_in) & 0x40 ? 0xff : 0x00;
                    else if(i == 2) bitmap_out_tmp[x] = (*bitmap_in) & 0x20 ? 0xff : 0x00;
                    else if(i == 3) bitmap_out_tmp[x] = (*bitmap_in) & 0x10 ? 0xff : 0x00;
                    else if(i == 4) bitmap_out_tmp[x] = (*bitmap_in) & 0x08 ? 0xff : 0x00;
                    else if(i == 5) bitmap_out_tmp[x] = (*bitmap_in) & 0x04 ? 0xff : 0x00;
                    else if(i == 6) bitmap_out_tmp[x] = (*bitmap_in) & 0x02 ? 0xff : 0x00;
                    else if(i == 7) {
                        bitmap_out_tmp[x] = (*bitmap_in) & 0x01 ? 0xff : 0x00;
                        bitmap_in++;
                    }
                }
                bitmap_out_tmp += stride;
            }
        }
        else if(fdsc->bpp == 2) {
            for(y = 0; y < gdsc->box_h; y ++) {
                for(x = 0; x < gdsc->box_w; x++, i++) {
                    i = i & 0x3;
                    if(i == 0) bitmap_out_tmp[x] = opa2_table[(*bitmap_in) >> 6];
                    else if(i == 1) bitmap_out_tmp[x] = opa2_table[((*bitmap_in) >> 4) & 0x3];
                    else if(i == 2) bitmap_out_tmp[x] = opa2_table[((*bitmap_in) >> 2) & 0x3];
                    else if(i == 3) {
                        bitmap_out_tmp[x] = opa2_table[((*bitmap_in) >> 0) & 0x3];
                        bitmap_in++;
                    }
                }
                bitmap_out_tmp += stride;
            }

        }
        else if(fdsc->bpp == 4) {
            for(y = 0; y < gdsc->box_h; y ++) {
                for(x = 0; x < gdsc->box_w; x++, i++) {
                    i = i & 0x1;
                    if(i == 0) {
                        bitmap_out_tmp[x] = opa4_table[(*bitmap_in) >> 4];
                    }
                    else if(i == 1) {
                        bitmap_out_tmp[x] = opa4_table[(*bitmap_in) & 0xF];
                        bitmap_in++;
                    }
                }
                bitmap_out_tmp += stride;
            }
        }
        // added by jethomson
        else if(fdsc->bpp == 8) {
            for(y = 0; y < gdsc->box_h; y ++) {
                for(x = 0; x < gdsc->box_w; x++, i++) {
                    bitmap_out_tmp[x] = *bitmap_in;
                    bitmap_in++;
                }
                bitmap_out_tmp += stride;
            }
        }
        return draw_buf;
    }
    //Handle compressed bitmap
    else {
#if LV_USE_FONT_COMPRESSED
        bool prefilter = fdsc->bitmap_format == LV_FONT_FMT_TXT_COMPRESSED;
        decompress(&fdsc->glyph_bitmap[gdsc->bitmap_index], bitmap_out, gdsc->box_w, gdsc->box_h,
                   (uint8_t)fdsc->bpp, prefilter);
        return draw_buf;
#else //!LV_USE_FONT_COMPRESSED
        LV_LOG_WARN("Compressed fonts is used but LV_USE_FONT_COMPRESSED is not enabled in lv_conf.h");
        return NULL;
#endif
    }

    //If not returned earlier then the letter is not found in this font
    return NULL;
}



// allows for sending a number back to function in main code so it can be printed to the serial port for debugging
void set_cb(void(*cb)(uint32_t)) {
  _cb = cb;
}