# lvgl_font_minimal
Minimal code needed to use fonts created by LVGL's font converter.

LVGL's Font Converter is an easy way to generate font c files that can be easily used in an LVGL project.
https://lvgl.io/tools/fontconverter

However I wished to use the font c files in my embedded projects without including all of LVGL.
The converter page says: "To use the Fonts without LVGL you need lv_font.c/h, lv_font_fmt_txt.c/h from here [https://github.com/lvgl/lvgl/tree/master/src/misc]" but I found this to be inaccurate.
Therefore I extracted a minimal amount of code from the LVGL project needed to use the fonts.

This project was created in PlatformIO. You should be able to drop the font c files output by the font converter into the lvgl_fonts folder with no need to modify them.
main.cpp is example code on a couple different methods for extracting the glyphs from the font file as bitmaps.
This code has been tested with 1, 2, 4, and 8 bpp font c files. It has not been test with 3 bpp font c files, nor has it been tested with any of the following options enabled in the font converter:
[ ] Enable Font compression (reduces size but results in slower rendering)
[ ] Horizontal subpixel rendering (may improve font quality but results in larger fonts)
[ ] Try to use glyph color info from font to create grayscale icons.

I previously used the fonts output by the 5.3 version of the font converter by including only a couple of LVGL files, but that converter has been taken down.
I was pretty frustrated I couldn't find the minimal code necessary to only use the font c files. I hope sharing my work here saves you some trouble.
