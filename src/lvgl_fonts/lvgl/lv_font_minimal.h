#pragma once

//#ifdef __cplusplus
//extern "C" {
//#endif

#include <stdlib.h>
#include <stdbool.h>

#define LV_ATTRIBUTE_EXTERN_DATA
#define LV_FONT_DECLARE(font_name) LV_ATTRIBUTE_EXTERN_DATA extern const lv_font_t font_name;
#define LV_ASSERT_NULL(p)

#define LV_LOG_TRACE(...) do {}while(0)
#define LV_LOG_INFO(...) do {}while(0)
#define LV_LOG_WARN(...) do {}while(0)
#define LV_LOG_ERROR(...) do {}while(0)
#define LV_LOG_USER(...) do {}while(0)
#define LV_LOG(...) do {} while(0)

#define LV_ATTRIBUTE_LARGE_CONST
#define LV_FONT_FMT_TXT_LARGE 0

#define LVGL_VERSION_MAJOR 9
#define LVGL_VERSION_MINOR 1
#define LVGL_VERSION_PATCH 1
#define LVGL_VERSION_INFO "dev"

#define LV_VERSION_CHECK(x,y,z) (x == LVGL_VERSION_MAJOR && (y < LVGL_VERSION_MINOR || (y == LVGL_VERSION_MINOR && z <= LVGL_VERSION_PATCH)))

#define LV_FONT_FMT_TXT_LARGE 0
#define LV_USE_FONT_COMPRESSED 0

#define LV_USE_FONT_PLACEHOLDER 1

//#define LV_COLOR_FORMAT_A8 0x0E, // taken from enum in lv_color.h


struct _lv_font_t;
typedef struct _lv_font_t lv_font_t;
typedef uint8_t lv_font_glyph_format_t;
typedef void lv_cache_entry_t; // this should be a struct, but it is not required
typedef uintptr_t lv_uintptr_t;


/** The bitmaps might be upscaled by 3 to achieve subpixel rendering.*/
enum _lv_font_subpx_t {
    LV_FONT_SUBPX_NONE,
    LV_FONT_SUBPX_HOR,
    LV_FONT_SUBPX_VER,
    LV_FONT_SUBPX_BOTH,
};

/** Adjust letter spacing for specific character pairs.*/
enum _lv_font_kerning_t {
    LV_FONT_KERNING_NORMAL,
    LV_FONT_KERNING_NONE,
};

/** The font format.*/
enum _lv_font_glyph_format_t {
    LV_FONT_GLYPH_FORMAT_NONE   = 0, /**< Maybe not visible*/

    /**< Legacy simple formats*/
    LV_FONT_GLYPH_FORMAT_A1     = 0x01, /**< 1 bit per pixel*/
    LV_FONT_GLYPH_FORMAT_A2     = 0x02, /**< 2 bit per pixel*/
    LV_FONT_GLYPH_FORMAT_A4     = 0x04, /**< 4 bit per pixel*/
    LV_FONT_GLYPH_FORMAT_A8     = 0x08, /**< 8 bit per pixel*/

    LV_FONT_GLYPH_FORMAT_IMAGE  = 0x09, /**< Image format*/

    /**< Advanced formats*/
    LV_FONT_GLYPH_FORMAT_VECTOR = 0x0A, /**< Vectorial format*/
    LV_FONT_GLYPH_FORMAT_SVG    = 0x0B, /**< SVG format*/
    LV_FONT_GLYPH_FORMAT_CUSTOM = 0xFF, /**< Custom format*/
};

/** Format of font character map.*/
enum _lv_font_fmt_txt_cmap_type_t {
    LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL,
    LV_FONT_FMT_TXT_CMAP_SPARSE_FULL,
    LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY,
    LV_FONT_FMT_TXT_CMAP_SPARSE_TINY,
};
//typedef _lv_font_fmt_txt_cmap_type_t lv_font_fmt_txt_cmap_type_t;
typedef uint8_t lv_font_fmt_txt_cmap_type_t;

/** Bitmap formats*/
typedef enum {
    LV_FONT_FMT_TXT_PLAIN      = 0,
    LV_FONT_FMT_TXT_COMPRESSED = 1,
    LV_FONT_FMT_TXT_COMPRESSED_NO_PREFILTER = 1,
} lv_font_fmt_txt_bitmap_format_t;




/** Describes the properties of a glyph.*/
typedef struct {
    const lv_font_t *
    resolved_font;  /**< Pointer to a font where the glyph was actually found after handling fallbacks*/
    uint16_t adv_w; /**< The glyph needs this space. Draw the next glyph after this width.*/
    uint16_t box_w; /**< Width of the glyph's bounding box*/
    uint16_t box_h; /**< Height of the glyph's bounding box*/
    int16_t ofs_x;  /**< x offset of the bounding box*/
    int16_t ofs_y;  /**< y offset of the bounding box*/
    lv_font_glyph_format_t format;  /**< Font format of the glyph see @lv_font_glyph_format_t*/
    uint8_t is_placeholder: 1;      /**< Glyph is missing. But placeholder will still be displayed*/

    union {
        uint32_t index;       /**< Unicode code point*/
        const void * src;     /**< Pointer to the source data used by image fonts*/
    } gid;                    /**< The index of the glyph in the font file. Used by the font cache*/
    lv_cache_entry_t * entry; /**< The cache entry of the glyph draw data. Used by the font cache*/
} lv_font_glyph_dsc_t;


#if LV_BIG_ENDIAN_SYSTEM
typedef struct {
    uint32_t reserved_2: 16;    /*Reserved to be used later*/
    uint32_t stride: 16;        /*Number of bytes in a row*/
    uint32_t h: 16;
    uint32_t w: 16;
    uint32_t flags: 16;         /*Image flags, see `lv_image_flags_t`*/
    uint32_t cf : 8;            /*Color format: See `lv_color_format_t`*/
    uint32_t magic: 8;          /*Magic number. Must be LV_IMAGE_HEADER_MAGIC*/
} lv_image_header_t;
#else
typedef struct {
    uint32_t magic: 8;          /*Magic number. Must be LV_IMAGE_HEADER_MAGIC*/
    uint32_t cf : 8;            /*Color format: See `lv_color_format_t`*/
    uint32_t flags: 16;         /*Image flags, see `lv_image_flags_t`*/

    uint32_t w: 16;
    uint32_t h: 16;
    uint32_t stride: 16;        /*Number of bytes in a row*/
    uint32_t reserved_2: 16;    /*Reserved to be used later*/
} lv_image_header_t;
#endif


typedef struct {
    lv_image_header_t header;
    uint32_t data_size;     /*Total buf size in bytes*/
    uint8_t * data;
    void * unaligned_data;  /*Unaligned address of `data`, used internally by lvgl*/
} lv_draw_buf_t;


/** Describe the properties of a font*/
struct _lv_font_t {
    /** Get a glyph's descriptor from a font*/
    bool (*get_glyph_dsc)(const lv_font_t *, lv_font_glyph_dsc_t *, uint32_t letter, uint32_t letter_next);

    /** Get a glyph's bitmap from a font*/
    const void * (*get_glyph_bitmap)(lv_font_glyph_dsc_t *, lv_draw_buf_t *);

    /** Release a glyph*/
    void (*release_glyph)(const lv_font_t *, lv_font_glyph_dsc_t *);

    /*Pointer to the font in a font pack (must have the same line height)*/
    int32_t line_height;         /**< The real line height where any text fits*/
    int32_t base_line;           /**< Base line measured from the bottom of the line_height*/
    uint8_t subpx   : 2;            /**< An element of `lv_font_subpx_t`*/
    uint8_t kerning : 1;            /**< An element of `lv_font_kerning_t`*/

    int8_t underline_position;      /**< Distance between the top of the underline and base line (< 0 means below the base line)*/
    int8_t underline_thickness;     /**< Thickness of the underline*/

    const void * dsc;               /**< Store implementation specific or run_time data or caching here*/
    const lv_font_t * fallback;   /**< Fallback font for missing glyph. Resolved recursively */
    void * user_data;               /**< Custom user data for font.*/
};


/**
 * Map codepoints to a `glyph_dsc`s
 * Several formats are supported to optimize memory usage
 * See https://github.com/lvgl/lv_font_conv/blob/master/doc/font_spec.md
 */
typedef struct {
    /** First Unicode character for this range*/
    uint32_t range_start;

    /** Number of Unicode characters related to this range.
     * Last Unicode character = range_start + range_length - 1*/
    uint16_t range_length;

    /** First glyph ID (array index of `glyph_dsc`) for this range*/
    uint16_t glyph_id_start;

    /*
    According the specification there are 4 formats:
        https://github.com/lvgl/lv_font_conv/blob/master/doc/font_spec.md

    For simplicity introduce "relative code point":
        rcp = codepoint - range_start

    and a search function:
        search a "value" in an "array" and returns the index of "value".

    Format 0 tiny
        unicode_list == NULL && glyph_id_ofs_list == NULL
        glyph_id = glyph_id_start + rcp

    Format 0 full
        unicode_list == NULL && glyph_id_ofs_list != NULL
        glyph_id = glyph_id_start + glyph_id_ofs_list[rcp]

    Sparse tiny
        unicode_list != NULL && glyph_id_ofs_list == NULL
        glyph_id = glyph_id_start + search(unicode_list, rcp)

    Sparse full
        unicode_list != NULL && glyph_id_ofs_list != NULL
        glyph_id = glyph_id_start + glyph_id_ofs_list[search(unicode_list, rcp)]
    */

    const uint16_t * unicode_list;

    /** if(type == LV_FONT_FMT_TXT_CMAP_FORMAT0_...) it's `uint8_t *`
     * if(type == LV_FONT_FMT_TXT_CMAP_SPARSE_...)  it's `uint16_t *`
     */
    const void * glyph_id_ofs_list;

    /** Length of `unicode_list` and/or `glyph_id_ofs_list`*/
    uint16_t list_length;

    /** Type of this character map*/
    lv_font_fmt_txt_cmap_type_t type;
} lv_font_fmt_txt_cmap_t;


/** This describes a glyph.*/
typedef struct {
#if LV_FONT_FMT_TXT_LARGE == 0
    uint32_t bitmap_index : 20;     /**< Start index of the bitmap. A font can be max 1 MB.*/
    uint32_t adv_w : 12;            /**< Draw the next glyph after this width. 8.4 format (real_value * 16 is stored).*/
    uint8_t box_w;                  /**< Width of the glyph's bounding box*/
    uint8_t box_h;                  /**< Height of the glyph's bounding box*/
    int8_t ofs_x;                   /**< x offset of the bounding box*/
    int8_t ofs_y;                   /**< y offset of the bounding box. Measured from the top of the line*/
#else
    uint32_t bitmap_index;          /**< Start index of the bitmap. A font can be max 4 GB.*/
    uint32_t adv_w;                 /**< Draw the next glyph after this width. 28.4 format (real_value * 16 is stored).*/
    uint16_t box_w;                 /**< Width of the glyph's bounding box*/
    uint16_t box_h;                 /**< Height of the glyph's bounding box*/
    int16_t ofs_x;                  /**< x offset of the bounding box*/
    int16_t ofs_y;                  /**< y offset of the bounding box. Measured from the top of the line*/
#endif
} lv_font_fmt_txt_glyph_dsc_t;


/*Describe store additional data for fonts*/
typedef struct {
    /*The bitmaps of all glyphs*/
    const uint8_t * glyph_bitmap;

    /*Describe the glyphs*/
    const lv_font_fmt_txt_glyph_dsc_t * glyph_dsc;

    /*Map the glyphs to Unicode characters.
     *Array of `lv_font_cmap_fmt_txt_t` variables*/
    const lv_font_fmt_txt_cmap_t * cmaps;

    /**
     * Store kerning values.
     * Can be `lv_font_fmt_txt_kern_pair_t *  or `lv_font_kern_classes_fmt_txt_t *`
     * depending on `kern_classes`
     */
    const void * kern_dsc;

    /*Scale kern values in 12.4 format*/
    uint16_t kern_scale;

    /*Number of cmap tables*/
    uint16_t cmap_num       : 9;

    /*Bit per pixel: 1, 2, 3, 4, 8*/
    uint16_t bpp            : 4;

    /*Type of `kern_dsc`*/
    uint16_t kern_classes   : 1;

    /*
     * storage format of the bitmap
     * from `lv_font_fmt_txt_bitmap_format_t`
     */
    uint16_t bitmap_format  : 2;
} lv_font_fmt_txt_dsc_t;


/** A simple mapping of kern values from pairs*/
typedef struct {
    /*To get a kern value of two code points:
       1. Get the `glyph_id_left` and `glyph_id_right` from `lv_font_fmt_txt_cmap_t
       2. for(i = 0; i < pair_cnt * 2; i += 2)
             if(glyph_ids[i] == glyph_id_left &&
                glyph_ids[i+1] == glyph_id_right)
                 return values[i / 2];
     */
    const void * glyph_ids;
    const int8_t * values;
    uint32_t pair_cnt   : 30;
    uint32_t glyph_ids_size : 2;    /*0: `glyph_ids` is stored as `uint8_t`; 1: as `uint16_t`*/
} lv_font_fmt_txt_kern_pair_t;


/** More complex but more optimal class based kern value storage*/
typedef struct {
    /*To get a kern value of two code points:
          1. Get the `glyph_id_left` and `glyph_id_right` from `lv_font_fmt_txt_cmap_t
          2. Get the class of the left and right glyphs as `left_class` and `right_class`
              left_class = left_class_mapping[glyph_id_left];
              right_class = right_class_mapping[glyph_id_right];
          3. value = class_pair_values[(left_class-1)*right_class_cnt + (right_class-1)]
        */

    const int8_t * class_pair_values;    /*left_class_cnt * right_class_cnt value*/
    const uint8_t * left_class_mapping;   /*Map the glyph_ids to classes: index -> glyph_id -> class_id*/
    const uint8_t * right_class_mapping;  /*Map the glyph_ids to classes: index -> glyph_id -> class_id*/
    uint8_t left_class_cnt;
    uint8_t right_class_cnt;
} lv_font_fmt_txt_kern_classes_t;

typedef struct {
    uint32_t gid_left;
    uint32_t gid_right;
} kern_pair_ref_t;

static const uint8_t opa2_table[4] = {0, 85, 170, 255};
static const uint8_t opa4_table[16] = {0,  17, 34,  51,
                                       68, 85, 102, 119,
                                       136, 153, 170, 187,
                                       204, 221, 238, 255
                                      };





bool lv_font_get_glyph_dsc(const lv_font_t * font_p, lv_font_glyph_dsc_t * dsc_out, uint32_t letter,
                           uint32_t letter_next);

//bool lv_font_get_glyph_dsc(const lv_font_t * font_p, lv_font_glyph_dsc_t*, unsigned int, unsigned int);


// * Used as `get_glyph_dsc` callback in lvgl's native font format if the font is uncompressed.
bool lv_font_get_glyph_dsc_fmt_txt(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter,
                                   uint32_t unicode_letter_next);
static uint32_t get_glyph_dsc_id(const lv_font_t * font, uint32_t letter);
static int32_t unicode_list_compare(const void * ref, const void * element);
static int8_t get_kern_value(const lv_font_t * font, uint32_t gid_left, uint32_t gid_right);
void * _lv_utils_bsearch(const void * key, const void * base, uint32_t n, uint32_t size,
                         int32_t (*cmp)(const void * pRef, const void * pElement));
static int32_t kern_pair_8_compare(const void * ref, const void * element);
static int32_t kern_pair_16_compare(const void * ref, const void * element);

// * Used as `get_glyph_bitmap` callback in lvgl's native font format if the font is uncompressed.
const void * lv_font_get_bitmap_fmt_txt(lv_font_glyph_dsc_t * g_dsc, lv_draw_buf_t * draw_buf);

// allows for sending a number back to function in main code so it can be printed to the serial port for debugging
void (*_cb)(uint32_t);
void set_cb(void(*cb)(uint32_t));

//#ifdef __cplusplus
//} /* extern "C" */
//#endif
