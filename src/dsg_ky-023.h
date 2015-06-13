#ifndef _DSG_KY_023_H_
#define _DSG_KY_023_H_

#include <stdint.h>
#include <dsg_button.h>
#include <dsg_gauge.h>

/**
 * KY-023 - Calibrated 2 axis and one button joystick.
 *
 * Storage: 32 bytes SRAM.
 *
 * The button returns true when pressed.
 *
 * The axis can return raw or calibrated values. The calibration
 * is done using minimum, zero and maximum for input (raw) and
 * the calibrated output. The output can be reversed - input of
 * 0 could return 127 and input of 1023 could return -128.
 */
class DSG_Ky023 {
public:
    DSG_Ky023(uint8_t x_pin, uint8_t y_pin, uint8_t btn_pin, uint16_t btn_debounce);
    ~DSG_Ky023();

    void begin(void);

    void end(void);

    void read(void);

    inline bool getBtn(void) const __attribute__ ((pure)) {
        return m_btn.get();
    }

    inline uint16_t getRawX(void) const __attribute__ ((pure)) {
        return m_x.getRaw();
    }

    inline uint16_t getRawY(void) const __attribute__ ((pure)) {
        return m_y.getRaw();
    }

    inline void calibrateX(uint16_t rmin, uint16_t r0, uint16_t rmax, int8_t cmin, int8_t c0, int8_t cmax) {
        m_x.calibrate(rmin, r0, rmax, cmin, c0, cmax);
    }

    inline void calibrateY(uint16_t rmin, uint16_t r0, uint16_t rmax, int8_t cmin, int8_t c0, int8_t cmax) {
        m_y.calibrate(rmin, r0, rmax, cmin, c0, cmax);
    }

    inline int8_t getX(void) const __attribute__ ((pure)) { // Try to call once, computation heavy
        return m_x.get();
    }

    inline int8_t getY(void) const __attribute__ ((pure)) { // Try to call once, computation heavy
        return m_y.get();
    }

protected:
    DSG_Gauge m_x;    // 12 bytes
    DSG_Gauge m_y;    // 12 bytes
    DSG_Button m_btn; // 8 bytes
};

#endif /* _DSG_KY_023_H_ */
