/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef FONT18_NORMAL
#define FONT18_NORMAL 1
#endif

#if FONT18_NORMAL

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xcc,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x8, 0x81, 0x10, 0x22, 0x4, 0x47, 0xfe, 0x22,
    0x4, 0x40, 0x88, 0x11, 0x1f, 0xf8, 0x88, 0x11,
    0x2, 0x20, 0x44, 0x0,

    /* U+0024 "$" */
    0x8, 0x4, 0xf, 0xf, 0xec, 0x9c, 0x42, 0x21,
    0x90, 0x78, 0x7, 0x2, 0xe1, 0x10, 0x8c, 0x47,
    0xac, 0x7c, 0x8, 0x4, 0x0,

    /* U+0025 "%" */
    0x78, 0x13, 0x30, 0xc8, 0x46, 0x21, 0x10, 0xcc,
    0xc1, 0xe6, 0x0, 0x10, 0x0, 0x80, 0x6, 0x78,
    0x33, 0x30, 0x88, 0x46, 0x21, 0x30, 0xcc, 0x81,
    0xe0,

    /* U+0026 "&" */
    0x1e, 0x6, 0x60, 0x84, 0x10, 0x82, 0x30, 0x2c,
    0x7, 0x3, 0xe0, 0xc6, 0x50, 0x5a, 0xe, 0x40,
    0xc4, 0x3c, 0x78, 0xc0,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x2d, 0x2d, 0x24, 0x92, 0x48, 0x92, 0x20,

    /* U+0029 ")" */
    0x99, 0x26, 0x49, 0x24, 0x92, 0x92, 0x80,

    /* U+002A "*" */
    0x27, 0xc9, 0xf2, 0x0,

    /* U+002B "+" */
    0x8, 0x8, 0x8, 0xff, 0x8, 0x8, 0x8, 0x8,

    /* U+002C "," */
    0xf0,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x8, 0xc6, 0x21, 0x18, 0x84, 0x62, 0x11, 0x8c,
    0x40,

    /* U+0030 "0" */
    0x3c, 0x31, 0x90, 0x50, 0x38, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x68, 0x26, 0x31, 0xe0,

    /* U+0031 "1" */
    0x37, 0xd1, 0x11, 0x11, 0x11, 0x11, 0x11,

    /* U+0032 "2" */
    0x3c, 0x62, 0xc1, 0x1, 0x1, 0x3, 0x2, 0x6,
    0xc, 0x18, 0x30, 0x60, 0x40, 0xff,

    /* U+0033 "3" */
    0xff, 0x7, 0x6, 0xc, 0x18, 0x30, 0x3c, 0x2,
    0x1, 0x1, 0x1, 0x81, 0xc2, 0x3c,

    /* U+0034 "4" */
    0x6, 0x3, 0x3, 0x81, 0x41, 0xa1, 0x90, 0x88,
    0xc4, 0x42, 0x61, 0x3f, 0xe0, 0x40, 0x20, 0x10,

    /* U+0035 "5" */
    0x7f, 0x30, 0x18, 0x8, 0x4, 0x2, 0xf1, 0x84,
    0x1, 0x0, 0x80, 0x40, 0x38, 0x16, 0x11, 0xf0,

    /* U+0036 "6" */
    0xc, 0xc, 0x4, 0x6, 0x2, 0x3, 0xf1, 0x8d,
    0x83, 0x80, 0xc0, 0x60, 0x38, 0x36, 0x31, 0xf0,

    /* U+0037 "7" */
    0xff, 0x3, 0x2, 0x6, 0x6, 0x4, 0xc, 0x8,
    0x18, 0x18, 0x10, 0x30, 0x20, 0x60,

    /* U+0038 "8" */
    0x1c, 0x11, 0x10, 0x48, 0x24, 0x11, 0x10, 0x70,
    0xc6, 0x80, 0xc0, 0x60, 0x30, 0x14, 0x11, 0xf0,

    /* U+0039 "9" */
    0x3e, 0x31, 0xb0, 0x70, 0x18, 0xc, 0x7, 0x6,
    0xc6, 0x3f, 0x1, 0x1, 0x80, 0x80, 0xc0, 0xc0,

    /* U+003A ":" */
    0xc0, 0xc0,

    /* U+003B ";" */
    0xc0, 0xf0,

    /* U+003C "<" */
    0x1, 0x7, 0x1c, 0x70, 0xc0, 0xc0, 0x30, 0xc,
    0x7, 0x1,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0x0, 0xff,

    /* U+003E ">" */
    0x80, 0xe0, 0x38, 0xe, 0x3, 0x3, 0xc, 0x30,
    0xe0, 0x80,

    /* U+003F "?" */
    0x3d, 0x8e, 0x8, 0x10, 0x60, 0x82, 0x8, 0x10,
    0x20, 0x0, 0x1, 0x2, 0x0,

    /* U+0040 "@" */
    0xf, 0x81, 0x83, 0x18, 0xc, 0x80, 0x28, 0x74,
    0xc6, 0x66, 0x21, 0x31, 0x9, 0x8c, 0xcc, 0x3d,
    0x90, 0x0, 0xc0, 0x3, 0x4, 0x7, 0xe0,

    /* U+0041 "A" */
    0x6, 0x0, 0x60, 0xf, 0x0, 0xb0, 0x9, 0x1,
    0x98, 0x11, 0x81, 0x8, 0x3f, 0xc2, 0x4, 0x60,
    0x46, 0x6, 0x40, 0x2c, 0x2,

    /* U+0042 "B" */
    0xfe, 0x40, 0xa0, 0x30, 0x18, 0xc, 0xb, 0xf9,
    0x6, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x37, 0xf0,

    /* U+0043 "C" */
    0x1f, 0xc, 0x34, 0x5, 0x0, 0x80, 0x20, 0x8,
    0x2, 0x0, 0x80, 0x20, 0x4, 0x1, 0x1, 0x30,
    0xc7, 0xc0,

    /* U+0044 "D" */
    0xfe, 0x10, 0x32, 0x3, 0x40, 0x28, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x80, 0x30, 0x6, 0x1, 0x40,
    0x68, 0x19, 0xfc, 0x0,

    /* U+0045 "E" */
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0xfe, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0xff,

    /* U+0046 "F" */
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xfe,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,

    /* U+0047 "G" */
    0xf, 0x86, 0x19, 0x81, 0x20, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x1f, 0x80, 0x30, 0x5, 0x0, 0xb0,
    0x13, 0xc, 0x3f, 0x0,

    /* U+0048 "H" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x60, 0x1f,
    0xfe, 0x1, 0x80, 0x60, 0x18, 0x6, 0x1, 0x80,
    0x60, 0x10,

    /* U+0049 "I" */
    0xff, 0xfc,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x41, 0x4, 0x10,
    0x61, 0xc9, 0xe0,

    /* U+004B "K" */
    0x81, 0x41, 0x21, 0x11, 0x9, 0x5, 0x3, 0x81,
    0xe0, 0x98, 0x46, 0x21, 0x10, 0x48, 0x34, 0xc,

    /* U+004C "L" */
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0xff,

    /* U+004D "M" */
    0x80, 0xe, 0x0, 0xf8, 0xf, 0xc0, 0x5b, 0x6,
    0xc8, 0x26, 0x63, 0x31, 0xb1, 0x85, 0xc, 0x38,
    0x60, 0x83, 0x0, 0x18, 0x0, 0xc0, 0x4,

    /* U+004E "N" */
    0x80, 0x70, 0x1e, 0x6, 0x81, 0xb0, 0x66, 0x18,
    0xc6, 0x31, 0x86, 0x60, 0xd8, 0x16, 0x7, 0x80,
    0xe0, 0x10,

    /* U+004F "O" */
    0xf, 0x83, 0xc, 0x60, 0x64, 0x2, 0x80, 0x18,
    0x1, 0x80, 0x18, 0x1, 0x80, 0x18, 0x1, 0x40,
    0x24, 0x6, 0x30, 0xc1, 0xf0,

    /* U+0050 "P" */
    0xfe, 0x41, 0xa0, 0x30, 0x18, 0xc, 0x6, 0xd,
    0xfc, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x0,

    /* U+0051 "Q" */
    0xf, 0x3, 0xc, 0x60, 0x64, 0x2, 0x80, 0x18,
    0x1, 0x80, 0x18, 0x1, 0x80, 0x18, 0x1, 0x41,
    0xb4, 0xe, 0x30, 0xe0, 0xfe, 0x0, 0x30,

    /* U+0052 "R" */
    0xfe, 0x20, 0xc8, 0xa, 0x2, 0x80, 0xa0, 0x28,
    0x33, 0xf8, 0x84, 0x21, 0x88, 0x32, 0x4, 0x81,
    0xa0, 0x20,

    /* U+0053 "S" */
    0x3e, 0x21, 0xa0, 0x10, 0x8, 0x7, 0x1, 0xf0,
    0x1e, 0x3, 0x80, 0x40, 0x30, 0x1c, 0x11, 0xf0,

    /* U+0054 "T" */
    0xff, 0xc1, 0x0, 0x40, 0x10, 0x4, 0x1, 0x0,
    0x40, 0x10, 0x4, 0x1, 0x0, 0x40, 0x10, 0x4,
    0x1, 0x0,

    /* U+0055 "U" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x5, 0x2, 0x61,
    0x87, 0x80,

    /* U+0056 "V" */
    0xc0, 0x24, 0x2, 0x60, 0x66, 0x4, 0x20, 0x43,
    0xc, 0x10, 0x81, 0x18, 0x19, 0x80, 0x90, 0xb,
    0x0, 0xf0, 0x6, 0x0, 0x60,

    /* U+0057 "W" */
    0xc0, 0xc1, 0xa0, 0xe0, 0xd0, 0x70, 0x4c, 0x28,
    0x26, 0x16, 0x31, 0x19, 0x18, 0x88, 0x88, 0x64,
    0x44, 0x32, 0x36, 0xb, 0xa, 0x5, 0x5, 0x3,
    0x83, 0x80, 0xc1, 0xc0, 0x60, 0x40,

    /* U+0058 "X" */
    0x60, 0x44, 0x18, 0xc6, 0x8, 0x81, 0xb0, 0x1c,
    0x1, 0x80, 0x70, 0xb, 0x3, 0x20, 0xc6, 0x10,
    0x46, 0xc, 0x80, 0xc0,

    /* U+0059 "Y" */
    0x40, 0x4c, 0x18, 0x82, 0x18, 0xc1, 0x10, 0x36,
    0x2, 0x80, 0x20, 0x4, 0x0, 0x80, 0x10, 0x2,
    0x0, 0x40, 0x8, 0x0,

    /* U+005A "Z" */
    0xff, 0x80, 0xc0, 0xc0, 0x40, 0x60, 0x20, 0x30,
    0x30, 0x10, 0x18, 0x8, 0xc, 0xc, 0x7, 0xfc,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8f,

    /* U+005C "\\" */
    0xc1, 0x4, 0x18, 0x20, 0x83, 0xc, 0x10, 0x61,
    0x82, 0x8, 0x30,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f,

    /* U+005E "^" */
    0x18, 0x70, 0x93, 0x34, 0x20,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0x99, 0x80,

    /* U+0061 "a" */
    0x7c, 0x8c, 0x8, 0x13, 0xf8, 0x60, 0xc1, 0xc6,
    0xf4,

    /* U+0062 "b" */
    0x80, 0x80, 0x80, 0x80, 0xbc, 0xc6, 0xc3, 0x81,
    0x81, 0x81, 0x81, 0xc3, 0xc6, 0xbc,

    /* U+0063 "c" */
    0x3c, 0x42, 0xc2, 0x80, 0x80, 0x80, 0x80, 0xc2,
    0x42, 0x3c,

    /* U+0064 "d" */
    0x1, 0x1, 0x1, 0x1, 0x3d, 0x63, 0xc3, 0x81,
    0x81, 0x81, 0x81, 0xc3, 0x63, 0x3d,

    /* U+0065 "e" */
    0x3c, 0x42, 0x81, 0x81, 0xff, 0x80, 0x80, 0xc0,
    0x63, 0x3c,

    /* U+0066 "f" */
    0x19, 0x8, 0x4f, 0x90, 0x84, 0x21, 0x8, 0x42,
    0x10,

    /* U+0067 "g" */
    0x3d, 0x63, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0x63, 0x3d, 0x1, 0x1, 0xc2, 0x3c,

    /* U+0068 "h" */
    0x80, 0x80, 0x80, 0x80, 0xbc, 0xc2, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81,

    /* U+0069 "i" */
    0xf0, 0xaa, 0xaa, 0xa0,

    /* U+006A "j" */
    0x18, 0xc0, 0x1, 0x8, 0x42, 0x10, 0x84, 0x21,
    0x8, 0x42, 0x17, 0x0,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x8, 0x71, 0xa6, 0x58, 0xe1,
    0xe2, 0x64, 0x48, 0xd0, 0xc0,

    /* U+006C "l" */
    0xaa, 0xaa, 0xaa, 0xb0,

    /* U+006D "m" */
    0xbc, 0xf6, 0x28, 0xa0, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41, 0x82, 0xc, 0x10,
    0x40,

    /* U+006E "n" */
    0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81,

    /* U+006F "o" */
    0x3c, 0x42, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0x42, 0x3c,

    /* U+0070 "p" */
    0xbc, 0xe6, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0xc6, 0xbc, 0x80, 0x80, 0x80, 0x80,

    /* U+0071 "q" */
    0x3d, 0x63, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0x63, 0x3d, 0x1, 0x1, 0x1, 0x1,

    /* U+0072 "r" */
    0x9f, 0x31, 0x8, 0x42, 0x10, 0x84, 0x0,

    /* U+0073 "s" */
    0x7d, 0x8e, 0x6, 0x7, 0x3, 0x81, 0xc1, 0xc6,
    0xf8,

    /* U+0074 "t" */
    0x21, 0x9, 0xf2, 0x10, 0x84, 0x21, 0x8, 0x41,
    0x80,

    /* U+0075 "u" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x43, 0x3d,

    /* U+0076 "v" */
    0xc1, 0xa0, 0x90, 0x4c, 0x62, 0x21, 0x90, 0xd8,
    0x28, 0x1c, 0x4, 0x0,

    /* U+0077 "w" */
    0xc3, 0xd, 0xc, 0x34, 0x38, 0x99, 0xa2, 0x24,
    0x98, 0x92, 0x42, 0xcd, 0xe, 0x1c, 0x18, 0x60,
    0x61, 0x80,

    /* U+0078 "x" */
    0x43, 0x31, 0xd, 0x82, 0x81, 0x80, 0xe0, 0xd0,
    0x4c, 0x63, 0x60, 0x80,

    /* U+0079 "y" */
    0xc1, 0xa0, 0x98, 0x4c, 0x62, 0x21, 0x90, 0x58,
    0x28, 0x1c, 0x4, 0x6, 0x3, 0x1, 0x1, 0x80,

    /* U+007A "z" */
    0xfe, 0x6, 0xc, 0x8, 0x18, 0x30, 0x20, 0x60,
    0xc0, 0xff,

    /* U+007B "{" */
    0x19, 0x8, 0x42, 0x11, 0x98, 0x61, 0x8, 0x42,
    0x10, 0xc3,

    /* U+007C "|" */
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xc0, 0x82, 0x8, 0x20, 0x83, 0x3, 0x30, 0x82,
    0x8, 0x20, 0x86, 0x30,

    /* U+007E "~" */
    0x73, 0x1c,

    /* U+007F "" */    
    0x0,

    /* U+5367 "卧" */
    0x0, 0x21, 0xfe, 0x42, 0x20, 0x84, 0x41, 0x8,
    0x82, 0x1f, 0xc4, 0x20, 0x8e, 0x41, 0x16, 0x82,
    0x27, 0x4, 0x47, 0xf8, 0x84, 0x41, 0x8, 0x82,
    0x11, 0x4, 0x3f, 0xc8, 0x0, 0x10,

    /* U+5385 "厅" */
    0x3f, 0xff, 0x20, 0x0, 0x20, 0x0, 0x20, 0x0,
    0x2f, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x40, 0x20, 0x40, 0x20, 0xc3, 0xe0,

    /* U+5BA2 "客" */
    0x1, 0x0, 0x1, 0x80, 0x7f, 0xfe, 0x44, 0x2,
    0x4f, 0xfa, 0x18, 0x18, 0x6c, 0x60, 0x43, 0xc0,
    0x7, 0xe0, 0xfc, 0x3f, 0xc0, 0x0, 0x1f, 0xf8,
    0x10, 0x8, 0x10, 0x8, 0x1f, 0xf8, 0x10, 0x8,

    /* U+5BA4 "室" */
    0x1, 0x80, 0x0, 0x80, 0x7f, 0xff, 0x40, 0x3,
    0x40, 0x3, 0x3f, 0xfc, 0x4, 0x20, 0x18, 0x18,
    0x3f, 0xfc, 0x1, 0x84, 0x1, 0x80, 0x3f, 0xfc,
    0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0xff, 0xff
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 103, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 75, .box_w = 1, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 96, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 5, .adv_w = 203, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 165, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 46, .adv_w = 236, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 202, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 55, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 92, .adv_w = 87, .box_w = 3, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 99, .adv_w = 87, .box_w = 3, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 106, .adv_w = 127, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 110, .adv_w = 173, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 118, .adv_w = 73, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 119, .adv_w = 113, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 120, .adv_w = 70, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 113, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 181, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 113, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 162, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 169, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 169, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 172, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 149, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 179, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 171, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 70, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 73, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 279, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 289, .adv_w = 173, .box_w = 8, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 294, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 304, .adv_w = 141, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 237, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 190, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 190, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 201, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 213, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 170, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 164, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 212, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 205, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 68, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 135, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 185, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 162, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 251, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 210, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 225, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 178, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 225, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 625, .adv_w = 181, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 174, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 173, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 201, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 190, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 276, .box_w = 17, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 746, .adv_w = 179, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 177, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 170, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 100, .box_w = 4, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 810, .adv_w = 97, .box_w = 6, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 100, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 829, .adv_w = 126, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 834, .adv_w = 130, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 835, .adv_w = 74, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 837, .adv_w = 153, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 846, .adv_w = 172, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 860, .adv_w = 153, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 870, .adv_w = 172, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 884, .adv_w = 161, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 894, .adv_w = 99, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 172, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 917, .adv_w = 166, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 931, .adv_w = 70, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 70, .box_w = 5, .box_h = 18, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 947, .adv_w = 145, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 960, .adv_w = 70, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 254, .box_w = 13, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 981, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 165, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1001, .adv_w = 172, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1015, .adv_w = 172, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1029, .adv_w = 107, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1036, .adv_w = 135, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1045, .adv_w = 101, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1054, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1064, .adv_w = 145, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1076, .adv_w = 226, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1094, .adv_w = 139, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 146, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1122, .adv_w = 140, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1132, .adv_w = 100, .box_w = 5, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1142, .adv_w = 63, .box_w = 1, .box_h = 17, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1145, .adv_w = 100, .box_w = 6, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1157, .adv_w = 149, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 1159, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1160, .adv_w = 288, .box_w = 15, .box_h = 16, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1190, .adv_w = 288, .box_w = 16, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1220, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1252, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x1e, 0x83b, 0x83d
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 21351, .range_length = 2110, .glyph_id_start = 97,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 2, 0, 2,
    3, 4, 0, 5, 6, 7, 0, 8,
    9, 10, 11, 0, 0, 0, 0, 0,
    0, 0, 12, 13, 14, 15, 16, 17,
    18, 0, 0, 19, 20, 21, 0, 0,
    15, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 0, 0, 0, 0,
    33, 0, 34, 35, 36, 0, 37, 38,
    39, 34, 0, 0, 40, 41, 34, 34,
    35, 35, 39, 42, 43, 44, 39, 45,
    46, 47, 45, 48, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 2, 0, 2,
    3, 4, 5, 6, 7, 8, 0, 9,
    10, 11, 12, 0, 0, 0, 0, 0,
    0, 0, 13, 0, 14, 0, 0, 0,
    14, 0, 0, 15, 0, 0, 0, 0,
    14, 0, 14, 0, 16, 17, 18, 19,
    20, 21, 22, 23, 0, 0, 0, 0,
    0, 0, 24, 0, 25, 25, 25, 26,
    25, 0, 0, 27, 0, 28, 29, 29,
    25, 29, 25, 29, 30, 31, 32, 33,
    34, 35, 33, 36, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -8, 0,
    -23, -6, -20, -12, 0, -29, 0, -5,
    -3, 1, 0, -6, 0, 0, -2, 0,
    -11, -8, 0, 0, 0, 0, 0, 0,
    -17, 0, 0, -13, 0, 0, 0, -17,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -20,
    -14, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -9, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, -8, -10,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, 0,
    0, -8, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, 0, 0, 0, -12, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -40, -26, -6, 0, 0, 0, -22,
    -20, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -32, -14, 0, 0, 0, 0, -6,
    -3, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, 0, -39, -5, -31, -21,
    0, -34, 0, 0, -5, 0, 0, 0,
    0, 0, 0, 0, -14, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, 0, 0, 0,
    -7, 0, -6, -5, -6, -10, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, -1, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, -3, 0, 0, 0,
    -6, -3, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, -6, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, 0, -17, 0,
    -9, 0, -10, -5, -15, -14, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -4, 0, 0,
    -8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -18, 0, -31, -4,
    0, 0, 0, 0, -6, 0, 0, -18,
    -8, 0, 0, 0, 0, 0, 0, -6,
    -3, -3, -12, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, -9, 0, -12, -5,
    -8, -18, -3, 0, 0, 0, 0, 0,
    0, -3, 0, 0, -7, -9, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -18, -12, -9, 0, -14, 0, 0,
    0, 0, 0, -9, -15, 0, 0, 0,
    0, -3, -14, -14, -23, -18, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -12, 0, 0,
    -39, -6, -35, -24, 0, -40, 0, 0,
    0, -6, 0, 0, 0, 0, -11, -7,
    -23, -14, 0, 0, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -24, 0, -46, 0, -6, 0, -7, -5,
    -12, -9, -6, -16, -14, 0, 0, 0,
    0, -11, 0, -12, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, 0, 0, 0,
    -9, 0, -7, -7, -13, -14, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -8, 0, -5, 0, -5, -3,
    0, -10, 0, -4, -6, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -7, 0, -3, 0, -8, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, -6, -3, -4, -17, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -39, -9, -45, -7, 0, 0, 0, 0,
    -8, 0, 0, -29, -29, -14, 0, 0,
    -26, -37, -6, -29, -32, -29, -31, -33,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, -8, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -20, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -31, -10, -45, -3, 0, 0, 0, 0,
    0, 0, 0, -25, -23, -10, 0, 0,
    -23, -21, -6, -21, -9, -9, -12, -12,
    -11, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -21, -5, -26, -2,
    0, 0, 0, 0, 0, 0, 0, -15,
    -13, -6, 0, 0, -14, -14, -3, -13,
    -9, -9, -12, -12, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, 0, -4, -8, -4, 0, 0,
    0, 0, 0, -2, -11, -6, 0, -2,
    -5, -9, -14, -12, -24, -21, 0, 0,
    -23, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -34, -14, -50, -9,
    0, 0, 0, 0, 0, 0, 0, -44,
    -41, -14, 0, 0, -43, -37, -17, -41,
    -29, -28, -29, -32, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -14, 0, 0, 0, -5, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, -8, -9, -12, -12, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 19, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -29, 0, -24, -14,
    -5, -45, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -2, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    -29, 0, -23, -13, -11, -41, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, -3, -9, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -29, 0, -13, -10,
    -5, -35, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -29, 0, -18, -10, -9, -33, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, -1, -4, 0, -9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -17, 0, -21, 0, 0, 0, 0, 0,
    0, 0, 0, -5, -5, 0, 0, 0,
    0, -4, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -26, 0, -23, -15, 0, -40, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, -43, -3, -14, -9,
    0, -23, 0, -3, -5, 0, 0, -1,
    0, -3, -2, -4, 0, 0, 0, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -2, -2, 0, 0, -15, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -26, 0, 0, 0,
    -22, -20, -14, -3, -4, 0, 0, 0,
    0, -3, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -36, 0, -15, -12, -9, -34, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -6, 0, -6, -3,
    0, -14, 0, 0, -2, 0, 0, 0,
    0, -2, 0, -1, 0, 0, 0, 0,
    -12, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, 0, -26, 0,
    -32, 0, -9, -9, -24, -29, -15, -2,
    -4, 0, 0, 0, 0, -2, 0, 0,
    0, 0, 0, 0, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -7, 0, -21, 0, -29, 0, -9, -9,
    -21, -28, -12, -2, -3, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    -31, 0, -12, -12, 0, -29, 0, -4,
    -10, 0, 0, -3, 0, -6, 0, -4,
    0, 0, 0, 0, -10, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -9, 0, 0, -32, 0, -9, -13,
    0, -31, 0, -1, -5, 0, 0, 0,
    0, -2, 0, -2, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 48,
    .right_class_cnt     = 36,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t Font18_Normal = {
#else
lv_font_t Font18_Normal = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT18_NORMAL*/

