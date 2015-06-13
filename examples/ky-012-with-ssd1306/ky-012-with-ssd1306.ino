#include <SPI.h>
#include <Wire.h>
// SRAM: 220
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dsg_button.h>
#include <dsg_gauge.h>
#include <dsg_ky-023.h>

#include <stdio.h>

#include "setup.h"

/**
 * Global variables/objects
 */
// Defines the display
OLED(display); // MEM: 1131 bytes RAM

DSG_Ky023 joy(KY012_X_PIN, KY012_Y_PIN, KY012_BTN_PIN, KY012_BTN_DEBOUNCE); // MEM: 32 bytes RAM

// Store position between calls
int16_t x = 0;
int16_t y = 0;

long startms;

/**
 * The setup function
 */
void setup(void) { // +2 bytes
#ifdef DSG_DEBUG
    Serial.begin(9600);
#endif
    // Sets the SPI clock divider relative to the system clock. On AVR based boards,
    // the dividers available are 2, 4, 8, 16, 32, 64 or 128. The default setting is
    // SPI_CLOCK_DIV4, which sets the SPI clock to one-quarter the frequency of the
    // system clock (4 MHz for the boards at 16 MHz).
    //SPI.setClockDivider(SPI_CLOCK_DIV2);

    // Initialize the display
    OLED_BEGIN(display); // +2 bytes
    // SRAM: 1,391
    // Show the display
    display.dim(true);
    display.display();

    delay(2000);

    // Initialize the Joystick
    joy.calibrateX(KY012_I_MIN, KY012_I_0, KY012_I_MAX, KY012_X_MIN, KY012_X_0, KY012_X_MAX);
    joy.calibrateY(KY012_J_MIN, KY012_J_0, KY012_J_MAX, KY012_Y_MIN, KY012_Y_0, KY012_Y_MAX);
    joy.begin();

    display.setTextColor(WHITE, BLACK);
    display.setTextSize(1); // 6x8 fixed width font
    // display.setTextSize(2); // 12x16 fixed width font
    // display.invertDisplay(true);

    display.clearDisplay();
    display.drawFastVLine(63, 0, 63, WHITE);

    display.setCursor(0, 0);
    display.print(F("Btn "));
    display.write(9);
    display.setCursor(0, 16);
    display.println(F("XRaw"));
    display.println(F("YRaw"));
    display.println(F("X"));
    display.println(F("Y"));
    display.println();
    display.print(F("DT "));

    startms = millis();
}

inline void print4(int num) {
    char buf[5];
    snprintf(buf, sizeof(buf), "%4d", num);
    display.print(buf);
}

inline void draw_pos(int16_t x, int16_t y, byte color = WHITE) {
    display.drawPixel(64 + 31 + x, 31 + y, color);
    display.drawPixel(64 + 32 + x, 31 + y, color);
    display.drawPixel(64 + 31 + x, 32 + y, color);
    display.drawPixel(64 + 32 + x, 32 + y, color);
}

void loop(void) {
    joy.read();
    draw_pos(x, y, BLACK);
    x = joy.getX();
    y = joy.getY();
    draw_pos(x, y, WHITE);

    display.setCursor(6*4, 8*0);
    if (joy.getBtn()) {
        display.dim(false);
        display.write(4);
    } else {
        display.dim(true);
        display.write(9);
    }

    display.setCursor(6*5, 8*2);
    print4(joy.getRawX());
    display.setCursor(6*5, 8*3);
    print4(joy.getRawY());

    display.setCursor(6*5, 8*4);
    print4(x);
    display.setCursor(6*5, 8*5);
    print4(y);

    long endms = millis();
    display.setCursor(6*2, 8*7);
    print4(endms - startms);
    startms = endms;

    display.display();
}

