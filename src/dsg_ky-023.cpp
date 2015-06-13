#include "dsg_ky-023.h"

DSG_Ky023::DSG_Ky023(uint8_t x_pin, uint8_t y_pin, uint8_t btn_pin, uint16_t btn_debounce) :
        m_x(x_pin), m_y(y_pin), m_btn(btn_pin, btn_debounce) {
}

DSG_Ky023::~DSG_Ky023() {
    // all members will be destroyed, the destructors call their .end() methods, no need to do it here.
}

void DSG_Ky023::begin(void) {
    m_x.begin();
    m_y.begin();
    m_btn.begin();
}

void DSG_Ky023::end(void) {
    m_x.end();
    m_y.end();
    m_btn.end();
}

void DSG_Ky023::read(void) {
    m_x.read();
    m_y.read();
    m_btn.read();
}
