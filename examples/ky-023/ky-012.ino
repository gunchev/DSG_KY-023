#include <avr/pgmspace.h>
#include <dsg_button.h>
#include <dsg_gauge.h>
#include <dsg_ky-023.h>

// --- Joystick -------------------------------------------------
#define KY012_BTN_PIN 2
#define KY012_X_PIN A0
#define KY012_Y_PIN A1
#define KY012_BTN_DEBOUNCE 25
// X Axis
#define KY012_I_MIN   63
#define KY012_I_0    511
#define KY012_I_MAX  960
#define KY012_X_MIN  -30
#define KY012_X_0      0
#define KY012_X_MAX   30
// Y Axis
#define KY012_J_MIN   63
#define KY012_J_0    511
#define KY012_J_MAX  960
#define KY012_Y_MIN  -30
#define KY012_Y_0      0
#define KY012_Y_MAX   30

/**
 * Global variables/objects
 */
DSG_Ky023 joy(KY012_X_PIN, KY012_Y_PIN, KY012_BTN_PIN, KY012_BTN_DEBOUNCE); // MEM: 32 bytes RAM

/**
 * The setup function
 */
void setup(void) {
    Serial.begin(9600); // MEM: 173 bytes RAM

    // Initialize the Joystick
    joy.calibrateX(KY012_I_MIN, KY012_I_0, KY012_I_MAX, KY012_X_MIN, KY012_X_0, KY012_X_MAX);
    joy.calibrateY(KY012_J_MIN, KY012_J_0, KY012_J_MAX, KY012_Y_MIN, KY012_Y_0, KY012_Y_MAX);
    joy.begin();
}

void loop(void) {
    joy.read();
    int x = joy.getX();
    int y = joy.getY();
    if (joy.getBtn()) {
        Serial.print(F("Btn: DOWN"));
    } else {
        Serial.print(F("Btn:   UP"));
    }
    Serial.print(F(", Xraw = "));
    Serial.print(joy.getRawX());
    Serial.print(F(", Yraw = "));
    Serial.print(joy.getRawY());
    Serial.print(F(", X = "));
    Serial.print(joy.getX());
    Serial.print(F(", Y = "));
    Serial.println(joy.getY());
    delay(500);
}

