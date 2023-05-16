/*******************************************************************************
 * Size: 20 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef FONT20
#define FONT20 1
#endif

#if FONT20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0025 "%" */
    0xb, 0xe0, 0x0, 0x3f, 0x40, 0xff, 0xf0, 0x3,
    0xf8, 0x7, 0xd7, 0xe0, 0x1f, 0xc0, 0x2e, 0xb,
    0x80, 0xfc, 0x0, 0xbc, 0x3e, 0xf, 0xd0, 0x0,
    0xff, 0xf4, 0xbe, 0x0, 0x1, 0xff, 0x47, 0xf0,
    0x0, 0x0, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x3,
    0xf4, 0x0, 0x0, 0x0, 0x2f, 0xc3, 0xfe, 0x0,
    0x1, 0xfc, 0x3f, 0xfe, 0x0, 0xf, 0xd1, 0xf4,
    0xbc, 0x0, 0xbe, 0x7, 0xc1, 0xf0, 0x7, 0xf0,
    0xf, 0x9f, 0xc0, 0x3f, 0x0, 0x2f, 0xfd, 0x3,
    0xf4, 0x0, 0x2f, 0xd0,

    /* U+2103 "℃" */
    0x7, 0xf4, 0x0, 0x7, 0xfe, 0x0, 0x2f, 0xfd,
    0x0, 0x3f, 0xff, 0xd0, 0x3c, 0x1f, 0x0, 0xff,
    0xff, 0xf4, 0x3c, 0xf, 0x3, 0xff, 0x5b, 0xfc,
    0x3c, 0x1f, 0x7, 0xf8, 0x1, 0xe0, 0x2f, 0xfd,
    0xf, 0xf0, 0x0, 0x0, 0xb, 0xf4, 0xf, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xd0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0xb, 0xf0, 0x0, 0x40,
    0x0, 0x0, 0x7, 0xfc, 0x1, 0xf4, 0x0, 0x0,
    0x3, 0xff, 0x9b, 0xfc, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xd0,
    0x0, 0x0, 0x0, 0x6, 0xf9, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 294, .box_w = 19, .box_h = 16, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 384, .box_w = 24, .box_h = 17, .ofs_x = 0, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x20de
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 37, .range_length = 8415, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
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
const lv_font_t Font20 = {
#else
lv_font_t Font20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT20*/

