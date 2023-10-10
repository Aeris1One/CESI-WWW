//
// Created by charlesp on 10/10/23.
//

#ifndef WWW_INPUT_H
#define WWW_INPUT_H

#include <Arduino.h>
#include <stdint.h>

class Input {
public:
    Input(uint8_t redPin, uint8_t greenPin);

    void update();

    bool is_red_pressed();

    bool was_red_pressed_for(uint32_t milliseconds);

    bool is_green_pressed();

    bool was_green_pressed_for(uint32_t milliseconds);

private:
    uint8_t buttonRed;
    uint8_t buttonGreen;
    uint32_t redState;
    uint32_t greenState;
};

#endif //WWW_INPUT_H