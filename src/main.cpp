#include <Arduino.h>


#include "lvgl_fonts/lvgl/lvgl.h"

#define CHAR_FONT_8BPP 0
#define CHAR_FONT_4BPP 1
#define CHAR_FONT_2BPP 2
#define CHAR_FONT_1BPP 3
#define SYMBOL_FONT 4

// uncomment different defines to test different fonts
#define TEST_FONT CHAR_FONT_8BPP
//#define TEST_FONT CHAR_FONT_4BPP
//#define TEST_FONT CHAR_FONT_2BPP
//#define TEST_FONT CHAR_FONT_1BPP
//#define TEST_FONT SYMBOL_FONT

#ifndef TEST_FONT
#  define TEST_FONT CHAR_FONT_8BPP
#endif


void print_Nbpp_char() {
  uint32_t c;
#if TEST_FONT == CHAR_FONT_8BPP
  LV_FONT_DECLARE(PublicPixel_8bpp_test); //OR use extern lv_font_t PublicPixel_8bpp_test;
  const lv_font_t* myfont = &PublicPixel_8bpp_test;
  // all characters: abcABC0123
  c = 'B'; // letter B --success
  //c = '\u0042'; // letter B --success
  //c = 0x0042; // letter B --success
  //c = 66; // letter B --success
#elif TEST_FONT == CHAR_FONT_4BPP
  LV_FONT_DECLARE(PublicPixel_4bpp_test);
  const lv_font_t* myfont = &PublicPixel_4bpp_test;
  // all characters: abcABC0123
  c = '0'; // number 0 --success
#elif TEST_FONT == CHAR_FONT_2BPP
  LV_FONT_DECLARE(PublicPixel_2bpp_test);
  const lv_font_t* myfont = &PublicPixel_2bpp_test;
  // all characters: abcABC0123
  c = '1'; // number 1 --success
#elif TEST_FONT == CHAR_FONT_1BPP
  LV_FONT_DECLARE(PublicPixel_1bpp_test);
  const lv_font_t* myfont = &PublicPixel_1bpp_test;
  // all characters: abcABC0123
  c = '2'; // number 2 --success
#elif TEST_FONT == SYMBOL_FONT
  LV_FONT_DECLARE(FontAwesome5FreeSymbols_8bpp_test);
  const lv_font_t* myfont = &FontAwesome5FreeSymbols_8bpp_test;
  // all symbols: 61457,61459,61461,61639,61671,61683,61787,61563
  //c = '\uf015'; // home symbol --fail
  //c = '\61461'; // home symbol --fail
  c = 0xf015; // home symbol --success
  //c = (uint32_t)61461; // home symbol --success
#endif

  Serial.print("print_Nbpp_char() -- start printing bitmap of character: ");
  Serial.println(c);

  lv_font_glyph_dsc_t g;
  bool g_ret = lv_font_get_glyph_dsc(myfont, &g, c, '\0');
  if (g_ret && g.gid.index) {
    lv_font_fmt_txt_dsc_t* fdsc = (lv_font_fmt_txt_dsc_t*)myfont->dsc;
    const lv_font_fmt_txt_glyph_dsc_t* gdsc = &fdsc->glyph_dsc[g.gid.index];

    //uint8_t width = lv_font_get_glyph_width(myfont, c, '\0');
    //uint8_t height = lv_font_get_line_height(myfont);
    uint8_t width = gdsc->box_w;
    uint8_t height = gdsc->box_h;

    Serial.print("bpp: ");
    Serial.print(fdsc->bpp);
    Serial.print(" width: ");
    Serial.print(width);
    Serial.print(" height: ");
    Serial.println(height);

    uint16_t bufsize = width*height;
    lv_draw_buf_t * draw_buf = NULL;
    //draw_buf = (lv_draw_buf_t *)malloc(sizeof(lv_draw_buf_t));
    //draw_buf->data = (uint8_t *) malloc(bufsize*sizeof(uint8_t));
    draw_buf = new lv_draw_buf_t;
    draw_buf->data = new uint8_t[bufsize];
    for (uint16_t i = 0; i < bufsize; i++) {
      (draw_buf->data)[i] = 0;
    }

    //uint8_t* glyph = (uint8_t *) myfont->get_glyph_bitmap(&g, draw_buf);
    myfont->get_glyph_bitmap(&g, draw_buf);
    uint8_t* glyph = draw_buf->data;

    if (glyph != nullptr && height > 0 && width > 0) {
      uint8_t n = 0;
      for (uint8_t j = 0; j < height; j++) {
        for (uint8_t k = 0; k < width; k++) {
          if (glyph[n] != 0) {
            Serial.print("%");
          }
          else {
            Serial.print(".");
          }
          n++;
        }
        Serial.println("");
      }
      Serial.print("finished printing bitmap");
    }
  }
  else {
    Serial.print("printing bitmap failed");
  }
}


// print_8bpp_char() is easier to use because it does not require allocating a draw_buf nor using get_glyph_bitmap()
void print_8bpp_char() {
  uint32_t c;
#if TEST_FONT == CHAR_FONT_8BPP
  LV_FONT_DECLARE(PublicPixel_8bpp_test); //OR use extern lv_font_t PublicPixel_8bpp_test;
  const lv_font_t* myfont = &PublicPixel_8bpp_test;
  // all characters: abcABC0123
  //c = 'C'; // letter C --success
  //c = '\u0043'; // letter C --success
  //c = 0x0043; // letter C --success
  c = 67; // letter C --success
#elif TEST_FONT == SYMBOL_FONT
  LV_FONT_DECLARE(FontAwesome5FreeSymbols_8bpp_test);
  const lv_font_t* myfont = &FontAwesome5FreeSymbols_8bpp_test;
  // all symbols: 61457,61459,61461,61639,61671,61683,61787,61563
  //c = '\uf015'; // home symbol --fail
  //c = '\61461'; // home symbol --fail
  //c = 0xf015; // home symbol --success
  c = (uint32_t)61461; // home symbol --success
#else
  // have to set up the font so we do not get a linker error
  // but return instead of printing because we do not want to confuse the user
  // when they have selected a font that is not 8 bpp.
  LV_FONT_DECLARE(PublicPixel_8bpp_test); //OR use extern lv_font_t PublicPixel_8bpp_test;
  const lv_font_t* myfont = &PublicPixel_8bpp_test;
  // all characters: abcABC0123
  c = 'a'; // letter a --success
  return;
#endif

  Serial.print("print_8bpp_char() -- start printing bitmap of character: ");
  Serial.println(c);

  lv_font_glyph_dsc_t g;
  bool g_ret = lv_font_get_glyph_dsc(myfont, &g, c, '\0');

  if (g_ret && g.gid.index) {
    lv_font_fmt_txt_dsc_t* fdsc = (lv_font_fmt_txt_dsc_t*)myfont->dsc;
    const lv_font_fmt_txt_glyph_dsc_t* gdsc = &fdsc->glyph_dsc[g.gid.index];
    const uint8_t* glyph = &fdsc->glyph_bitmap[gdsc->bitmap_index];

    //uint8_t width = lv_font_get_glyph_width(myfont, c, '\0');
    //uint8_t height = lv_font_get_line_height(myfont);
    uint8_t width = gdsc->box_w;
    uint8_t height = gdsc->box_h;

    Serial.print("bpp: ");
    Serial.print(fdsc->bpp);
    Serial.print(" width: ");
    Serial.print(width);
    Serial.print(" height: ");
    Serial.println(height);

    if (glyph != nullptr && height > 0 && width > 0) {
      uint8_t n = 0;
      for (uint8_t j = 0; j < height; j++) {
        for (uint8_t k = 0; k < width; k++) {
          if (glyph[n] != 0) {
            Serial.print("%");
          }
          else {
            Serial.print(".");
          }
          n++;
        }
        Serial.println("");
      }
      Serial.print("finished printing bitmap");
    }
  }
  else {
    Serial.print("printing bitmap failed");
  }
}


void cb_dbg_print(uint32_t i) {
  Serial.println(i);
}


void setup() {
  Serial.begin(115200);
  delay(1000);

  //set_cb(&cb_dbg_print);

  print_Nbpp_char();
  Serial.println("");
  print_8bpp_char();

}

void loop() {
}