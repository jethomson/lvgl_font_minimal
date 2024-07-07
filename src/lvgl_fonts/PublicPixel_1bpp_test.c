/*******************************************************************************
 * Public Domain: https://creativecommons.org/publicdomain/zero/1.0/deed.en
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font PublicPixel-E447g.ttf --symbols abcABC0123 --format lvgl -o PublicPixel_1bpp_test.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef PUBLICPIXEL_1BPP_TEST
#define PUBLICPIXEL_1BPP_TEST 1
#endif

#if PUBLICPIXEL_1BPP_TEST

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x3f, 0xf0, 0xff, 0xcf, 0xf, 0xfc, 0x3f, 0xf0,
    0x3f, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xc0, 0xff, 0xc3, 0xff, 0xf, 0x3f, 0xf0, 0xff,
    0xc0,

    /* U+0031 "1" */
    0xff, 0xf, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0,
    0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf,
    0x0, 0xf0, 0xff, 0xff, 0xff,

    /* U+0032 "2" */
    0x3f, 0xf0, 0xff, 0xcf, 0x3, 0xfc, 0xf, 0x0,
    0xf0, 0x3, 0xc0, 0xfc, 0x3, 0xf0, 0x3c, 0x0,
    0xf0, 0xf, 0x0, 0x3c, 0x0, 0xff, 0xff, 0xff,
    0xf0,

    /* U+0033 "3" */
    0x3f, 0xf0, 0xff, 0xcf, 0x3, 0xfc, 0xf, 0x0,
    0x3c, 0x0, 0xf0, 0xff, 0x3, 0xfc, 0x0, 0x3c,
    0x0, 0xff, 0x3, 0xfc, 0xf, 0x3f, 0xf0, 0xff,
    0xc0,

    /* U+0041 "A" */
    0xf, 0xc0, 0x3f, 0x3, 0xcf, 0xf, 0x3c, 0xf0,
    0x3f, 0xc0, 0xff, 0x3, 0xfc, 0xf, 0xff, 0xff,
    0xff, 0xff, 0x3, 0xfc, 0xf, 0xf0, 0x3f, 0xc0,
    0xf0,

    /* U+0042 "B" */
    0xff, 0xf3, 0xff, 0xcf, 0x3, 0xfc, 0xf, 0xf0,
    0x3f, 0xc0, 0xff, 0xff, 0x3f, 0xfc, 0xf0, 0x3f,
    0xc0, 0xff, 0x3, 0xfc, 0xf, 0xff, 0xf3, 0xff,
    0xc0,

    /* U+0043 "C" */
    0x3f, 0xf0, 0xff, 0xcf, 0x3, 0xfc, 0xf, 0xf0,
    0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0, 0xf0, 0x3,
    0xc0, 0xf, 0x3, 0xfc, 0xf, 0x3f, 0xf0, 0xff,
    0xc0,

    /* U+0061 "a" */
    0x3f, 0xf0, 0xff, 0xc0, 0x3, 0xc0, 0xf, 0x3f,
    0xfc, 0xff, 0xff, 0x3, 0xfc, 0xf, 0x3f, 0xfc,
    0xff, 0xf0,

    /* U+0062 "b" */
    0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0, 0xff,
    0xf3, 0xff, 0xcf, 0x3, 0xfc, 0xf, 0xf0, 0x3f,
    0xc0, 0xff, 0x3, 0xfc, 0xf, 0xff, 0xf3, 0xff,
    0xc0,

    /* U+0063 "c" */
    0x3f, 0xf0, 0xff, 0xcf, 0x3, 0xfc, 0xf, 0xf0,
    0x3, 0xc0, 0xf, 0x3, 0xfc, 0xf, 0x3f, 0xf0,
    0xff, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 256, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 256, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 256, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x1, 0x2, 0x3, 0x11, 0x12, 0x13, 0x31,
    0x32, 0x33
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 52, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 10, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t PublicPixel_1bpp_test = {
#else
lv_font_t PublicPixel_1bpp_test = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if PUBLICPIXEL_1BPP_TEST*/

