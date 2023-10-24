//
// Created by charlesp on 10/10/23.
//

#ifndef WWW_LED_H
#define WWW_LED_H

#include <Arduino.h>
#include <stdint.h>
#include <ChainableLED.h>

class Output {
public:
    Output(uint8_t pinCIN, uint8_t pinDIN);

    void update();

    void set_mode(uint8_t new_mode);

private:
    ChainableLED led;
    uint8_t mode;
    uint32_t last_update;
    bool state;
};

#endif //WWW_LED_H
