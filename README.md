# Arduino KY-023 - Calibrated 2 axis and one button joystick.

See https://tkkrlab.nl/wiki/Arduino_KY-023_XY-axis_joystick_module

The button returns true when pressed.

The axis can return raw or calibrated values. The calibration
is done using minimum, zero and maximum for input (raw) and
the calibrated output. The output can be reversed - input of
0 could return 127 and input of 1023 could return -128.

Requires [DSG_Button](https://github.com/mr700/DSG_Button.git) and [DSG_Gauge](https://github.com/mr700/DSG_Gauge.git) libraries.

Classes: DSG_Ky023.

Storage: 32 bytes RAM.
