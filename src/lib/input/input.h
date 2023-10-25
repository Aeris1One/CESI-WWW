//
// Created by charlesp on 10/10/23.
//

#ifndef WWW_INPUT_H
#define WWW_INPUT_H

#include <Arduino.h>

class Input {
public:
    Input(uint8_t redPin, uint8_t greenPin);

    void update();

    void resetFlags();

    bool red_short_flag_raised();

    bool red_long_flag_raised();

    bool green_short_flag_raised();

    bool green_long_flag_raised();

private:
    uint8_t buttonRed;
    uint8_t buttonGreen;

    uint8_t redState;
    uint8_t greenState;

    bool red_short_flag;
    bool red_long_flag;
    bool green_short_flag;
    bool green_long_flag;
};

#endif //WWW_INPUT_H