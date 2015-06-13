#ifndef _SETUP_H_
#define _SETUP_H_

// --- Joystick -------------------------------------------------
#define KY012_BTN_PIN       2
#define KY012_X_PIN        A0
#define KY012_Y_PIN        A1
#define KY012_BTN_DEBOUNCE 25
// X Axis
#define KY012_I_MIN    0
#define KY012_I_0    510
#define KY012_I_MAX 1023
#define KY012_X_MIN  -30
#define KY012_X_0      0
#define KY012_X_MAX   30
// Y Axis
#define KY012_J_MIN    0
#define KY012_J_0    510
#define KY012_J_MAX 1023
#define KY012_Y_MIN  -30
#define KY012_Y_0      0
#define KY012_Y_MAX   30

// --- OLED 128x64 BW -------------------------------------------
// Uncomment this block to use software SPI (the default case):
// SCL, the clock
#define OLED_CLK    9
// OLED_MOSI is labeled SDA
#define OLED_MOSI  10
// RST, can be connected to the RST next to GND and VIN instead
#define OLED_RESET 11
// D/C
#define OLED_DC    12
// Not available on my display, blinks the led nicely ;-)
#define OLED_CS    13
#define OLED(name) Adafruit_SSD1306 name(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS)
#define OLED_BEGIN(name) name.begin(SSD1306_SWITCHCAPVCC)
//
/* Uncomment this block to use hardware SPI
#define OLED_DC     6
#define OLED_CS     7
#define OLED_RESET  8
#define OLED(name) Adafruit_SSD1306 name(OLED_DC, OLED_RESET, OLED_CS);
#define OLED_BEGIN(name) name.begin(SSD1306_SWITCHCAPVCC)
*/
/* Uncomment this block to use I2C
#define OLED_RESET 4
#define OLED_ADDR 0x3C

#define OLED(name) Adafruit_SSD1306 name(OLED_RESET)
#define OLED_BEGIN(name) name.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)
*/

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#endif // _SETUP_H_
