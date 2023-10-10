#include "input.h"
#include <Arduino.h>

Input::Input(uint8_t redPin, uint8_t greenPin) {
    pinMode(redPin, INPUT_PULLUP);
    pinMode(greenPin, INPUT_PULLUP);
    buttonRed = redPin;
    buttonGreen = greenPin;
    redState = 0;
    greenState = 0;
}

void Input::update() {
    if ((digitalRead(buttonRed) == LOW) & (redState == 0)) {
        redState = millis();
    } else if (digitalRead(buttonRed) == HIGH) {
        redState = 0;
    }
    if ((digitalRead(buttonGreen) == LOW) & (greenState == 0)) {
        greenState = millis();
    } else if (digitalRead(buttonGreen) == HIGH) {
        greenState = 0;
    }
}


bool Input::was_red_pressed_for(uint32_t milliseconds) {
    if (redState == 0) {
        return false;
    }
    return ((millis() - redState) > milliseconds);
}

bool Input::was_green_pressed_for(uint32_t milliseconds) {
    if (greenState == 0) {
        return false;
    }
    return ((millis() - greenState) > milliseconds);
}

bool Input::is_red_pressed() {
    return was_red_pressed_for(100);
}

bool Input::is_green_pressed() {
    return was_green_pressed_for(100);
}
