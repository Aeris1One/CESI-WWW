#include "input.h"
#include <Arduino.h>

Input::Input(uint8_t redPin, uint8_t greenPin) {
    pinMode(redPin, INPUT_PULLUP);
    pinMode(greenPin, INPUT_PULLUP);
    buttonRed = redPin;
    buttonGreen = greenPin;
    redState = 0;
    greenState = 0;
    red_short_flag = false;
    red_long_flag = false;
    green_short_flag = false;
    green_long_flag = false;
}

void Input::update() {
    // NOTE: We want flag for short press to be raised only after the button was released
    // in order to not mess up with long press detection. But we want the flag for long press
    // to be raised as soon as 5s passed, even if still pressed.

    // GREEN BUTTON
    if (digitalRead(buttonGreen) == LOW) {
        greenState += 1;
    } else {
        if (50 > greenState && greenState > 0) {
            green_short_flag = true;
        }
        greenState = 0;
    }

    // RED BUTTON
    if (digitalRead(buttonRed) == LOW) {
        redState += 1;
    } else {
        if (50 > redState && redState > 0) {
            red_short_flag = true;
        }
        redState = 0;
    }

    // RAISE FLAGS
    if (redState == 50) {
        red_long_flag = true;
        red_short_flag = false;
    }
    if (greenState == 50) {
        green_long_flag = true;
        green_short_flag = false;
    }
}

void Input::resetFlags() {
    red_short_flag = false;
    red_long_flag = false;
    green_short_flag = false;
    green_long_flag = false;
}

bool Input::red_short_flag_raised() {
    return red_short_flag;
}

bool Input::red_long_flag_raised() {
    return red_long_flag;
}

bool Input::green_short_flag_raised() {
    return green_short_flag;
}

bool Input::green_long_flag_raised() {
    return green_long_flag;
}
