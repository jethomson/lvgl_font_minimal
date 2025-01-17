/*******************************************************************************
 * https://fontawesome.com/license/free
 * https://creativecommons.org/licenses/by/4.0/
 * Size: 16 px
 * Bpp: 8
 * Opts: --bpp 8 --size 16 --no-compress --font FontAwesome5-Solid+Brands+Regular.woff --range 61457,61459,61461,61639,61671,61683,61787,61563 --format lvgl -o FontAwesome5FreeSymbols_8bpp_test.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONTAWESOME5FREESYMBOLS_8BPP_TEST
#define FONTAWESOME5FREESYMBOLS_8BPP_TEST 1
#endif

#if FONTAWESOME5FREESYMBOLS_8BPP_TEST

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+F011 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x47, 0xfa,
    0xe2, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0x18, 0x0, 0x6c, 0xff,
    0xff, 0x14, 0x0, 0x33, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x59, 0xf9, 0xd2, 0x2, 0x6c, 0xff,
    0xff, 0x14, 0x30, 0xfd, 0xd5, 0x1d, 0x0, 0x0,
    0x0, 0x3c, 0xfa, 0xff, 0xf6, 0x11, 0x6c, 0xff,
    0xff, 0x14, 0x5f, 0xff, 0xff, 0xd2, 0x6, 0x0,
    0x2, 0xd6, 0xff, 0xf6, 0x41, 0x0, 0x6c, 0xff,
    0xff, 0x14, 0x0, 0x91, 0xff, 0xff, 0x7d, 0x0,
    0x49, 0xff, 0xff, 0x75, 0x0, 0x0, 0x6c, 0xff,
    0xff, 0x14, 0x0, 0x3, 0xcd, 0xff, 0xe6, 0x3,
    0x93, 0xff, 0xf7, 0xe, 0x0, 0x0, 0x6c, 0xff,
    0xff, 0x14, 0x0, 0x0, 0x5d, 0xff, 0xff, 0x38,
    0xb8, 0xff, 0xcf, 0x0, 0x0, 0x0, 0x6c, 0xff,
    0xff, 0x14, 0x0, 0x0, 0x26, 0xff, 0xff, 0x59,
    0xbe, 0xff, 0xc4, 0x0, 0x0, 0x0, 0x47, 0xfa,
    0xe3, 0x6, 0x0, 0x0, 0x1d, 0xff, 0xff, 0x62,
    0xa2, 0xff, 0xeb, 0x2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x46, 0xff, 0xff, 0x48,
    0x64, 0xff, 0xff, 0x4e, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xa7, 0xff, 0xfa, 0xe,
    0xf, 0xf0, 0xff, 0xe1, 0x17, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x52, 0xfe, 0xff, 0xa5, 0x0,
    0x0, 0x62, 0xff, 0xff, 0xdc, 0x3b, 0x0, 0x0,
    0x0, 0x5, 0x72, 0xfa, 0xff, 0xf0, 0x21, 0x0,
    0x0, 0x0, 0x95, 0xff, 0xff, 0xff, 0xd5, 0xac,
    0xb4, 0xec, 0xff, 0xff, 0xf7, 0x47, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6b, 0xf7, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xdb, 0x38, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x19, 0x7a, 0xbb, 0xd6,
    0xcc, 0xa9, 0x5c, 0x5, 0x0, 0x0, 0x0, 0x0,

    /* U+F013 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xb1,
    0xb2, 0x8f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3b, 0x7, 0x7, 0x6c, 0xff, 0xff,
    0xff, 0xff, 0x6d, 0x7, 0x9, 0x3e, 0x0, 0x0,
    0x0, 0x41, 0xfd, 0xde, 0xd3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd3, 0xe0, 0xfd, 0x41, 0x0,
    0x2, 0xdd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0x2,
    0x4c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x99,
    0x98, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4c,
    0xc, 0x8e, 0xfd, 0xff, 0xff, 0xf0, 0x22, 0x0,
    0x0, 0x22, 0xf0, 0xff, 0xff, 0xfd, 0x8e, 0xc,
    0x0, 0x0, 0xf5, 0xff, 0xff, 0x98, 0x0, 0x0,
    0x0, 0x0, 0x98, 0xff, 0xff, 0xf5, 0x0, 0x0,
    0x0, 0x0, 0xf5, 0xff, 0xff, 0x98, 0x0, 0x0,
    0x0, 0x0, 0x99, 0xff, 0xff, 0xf4, 0x0, 0x0,
    0xc, 0x8d, 0xfd, 0xff, 0xff, 0xf0, 0x22, 0x0,
    0x0, 0x22, 0xf0, 0xff, 0xff, 0xfd, 0x8d, 0xc,
    0x4c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x98,
    0x98, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x4c,
    0x2, 0xdd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0x2,
    0x0, 0x42, 0xfd, 0xe0, 0xd3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd3, 0xdf, 0xfd, 0x41, 0x0,
    0x0, 0x0, 0x3e, 0x9, 0x7, 0x6e, 0xff, 0xff,
    0xff, 0xff, 0x6d, 0x7, 0x8, 0x3d, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8e, 0xb2,
    0xb2, 0x8f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F015 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3d,
    0xdd, 0xdc, 0x38, 0x0, 0x36, 0xff, 0xff, 0x36,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x65, 0xfa, 0xff, 0xff, 0xf8, 0x5e, 0x40, 0xff,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4, 0x93, 0xff, 0xff, 0x91, 0x91, 0xff, 0xff,
    0xbc, 0xff, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x12, 0xbc, 0xff, 0xf9, 0x60, 0x2f, 0x2f,
    0x60, 0xf9, 0xff, 0xff, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x2a, 0xdc, 0xff, 0xe9, 0x3a, 0x58,
    0xf6, 0xf6, 0x58, 0x3a, 0xe9, 0xff, 0xff, 0x4c,
    0x0, 0x0, 0x0, 0x4b, 0xf1, 0xff, 0xcf, 0x1f,
    0x83, 0xff, 0xff, 0xff, 0xff, 0x83, 0x1f, 0xcf,
    0xff, 0xee, 0x47, 0x0, 0x74, 0xfd, 0xff, 0xac,
    0x16, 0xae, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xae, 0x16, 0xac, 0xff, 0xfd, 0x73, 0xc4, 0xfe,
    0x81, 0x20, 0xd1, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd0, 0x20, 0x81, 0xfe, 0xc4,
    0x18, 0x48, 0x0, 0xea, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe9, 0x0,
    0x48, 0x18, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xff, 0x91, 0x0, 0x0, 0x8f, 0xff,
    0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x80, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x80, 0xff, 0xff, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xee, 0xff, 0xff,
    0xff, 0x6d, 0x0, 0x0, 0x6d, 0xff, 0xff, 0xff,
    0xee, 0x0, 0x0, 0x0,

    /* U+F07B "" */
    0x87, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x1f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf,
    0x1f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x87,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9,
    0x87, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x87,

    /* U+F0C7 "" */
    0x87, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xce, 0x1f, 0x0, 0x0, 0xfa, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0x1f, 0x0, 0xff, 0xff, 0x8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x13, 0xff, 0xff,
    0xdf, 0x1f, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xce,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xb3, 0x1a, 0x1a,
    0xb4, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x1a, 0x0, 0x0, 0x1a, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x1a, 0x0, 0x0, 0x1a, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb3,
    0x1a, 0x1a, 0xb3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x87, 0xfa,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfa, 0x87,

    /* U+F0E7 "" */
    0x0, 0x2, 0xdd, 0xff, 0xff, 0xff, 0xff, 0xdb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1d, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xc9, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x76,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x62, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x24, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x84, 0xff, 0xff, 0xff, 0xff, 0xd1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa6, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdc, 0x0,
    0x0, 0xc8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xaf, 0x0, 0x0, 0xea, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x23, 0x0,
    0x0, 0xda, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xa7, 0xff, 0xff, 0xe6, 0xc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0xff, 0xff,
    0x5f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x20, 0xff, 0xff, 0xc9, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5d, 0xff, 0xfe, 0x38,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x99, 0xff, 0xa2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xd6, 0xf4, 0x1a, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xda, 0x71, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F0F3 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc3, 0xc3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x28, 0xff, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18,
    0xbe, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x14, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe2, 0x11, 0x0, 0x0,
    0x0, 0x0, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x8d, 0x0, 0x0, 0x0, 0x0,
    0xe2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdf, 0x0, 0x0, 0x0, 0x1, 0xfd, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
    0x1, 0x0, 0x0, 0x10, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf, 0x0,
    0x0, 0x3a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x39, 0x0, 0x0, 0x83,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x83, 0x0, 0x1f, 0xed, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xec, 0x1f, 0xcd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcd,
    0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xe4, 0xff, 0xff, 0xe3, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x49,
    0xe4, 0xe4, 0x49, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F15B "" */
    0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0xd7, 0x1f, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x0, 0xff, 0xdf, 0x1f, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0,
    0xff, 0xff, 0xdf, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x0, 0xff, 0xff, 0xff, 0xd7,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x2a,
    0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xd6, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 256, .adv_w = 256, .box_w = 16, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 512, .adv_w = 288, .box_w = 18, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 764, .adv_w = 256, .box_w = 16, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 956, .adv_w = 224, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1152, .adv_w = 160, .box_w = 12, .box_h = 16, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 1344, .adv_w = 224, .box_w = 14, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1568, .adv_w = 192, .box_w = 12, .box_h = 16, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x2, 0x4, 0x6a, 0xb6, 0xd6, 0xe2, 0x14a
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 61457, .range_length = 331, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 8, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .bpp = 8,
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
const lv_font_t FontAwesome5FreeSymbols_8bpp_test = {
#else
lv_font_t FontAwesome5FreeSymbols_8bpp_test = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -6,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if FONTAWESOME5FREESYMBOLS_8BPP_TEST*/

