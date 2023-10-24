#include "led.h"
#include <Arduino.h>
#include <ChainableLED.h>

Output::Output(uint8_t pinCIN, uint8_t pinDIN) {
    pinMode(pinCIN, OUTPUT);
    pinMode(pinDIN, OUTPUT);
    this->led = ChainableLED(pinCIN, pinDIN, 1);
    led.setColorRGB(0, 0, 0, 0);
    mode = 0;
    last_update = 0;
}

void Output::set_mode(uint8_t new_mode) {
    this->mode = new_mode;
    switch (new_mode) {
        case 0: {
            // 0: Initialisation
            led.setColorRGB(0, 255, 255, 255);
            break;
        }
        case 1: {
            // 1: Mode Standard
            led.setColorRGB(0, 0, 255, 0);
            break;
        }
        case 2: {
            // 2: Mode Configuration
            led.setColorRGB(0, 255, 255, 0);
            break;
        }
        case 3: {
            // 3: Mode Eco
            led.setColorRGB(0, 0, 0, 255);
            break;
        }
        case 4: {
            // 4: Mode Maintenance
            led.setColorRGB(0, 255, 165, 0);
            break;
        }
        default: {
            if ((mode < 1) & (mode > 10)) {
                Serial.println("Mode inconnu");
                led.setColorRGB(0, 255, 0, 0);
            }
            // 5: Erreur RTC
            // 6: Erreur GPS
            // 7: Erreur Capteur
            // 8: Erreur SD pleine
            // 9: Erreur Capteur (valeur incohérente)
            // 10: Erreur accès SD
            led.setColorRGB(0, 255, 0, 0);
            last_update = millis();
            break;
        }
    }
}


void Output::update() {
    uint32_t next_update;
    if (millis() < last_update) {
        // millis() just overflowed
        last_update = millis();
    }

    if ((mode > 8) & (state)) {
        next_update = last_update + 2000;
    } else {
        next_update = last_update + 1000;
    }

    if (next_update < millis()) {
        switch (mode) {
            case 5: {
                if (state) {
                    led.setColorRGB(0, 255, 0, 0);
                } else {
                    led.setColorRGB(0, 0, 0, 255);
                }
                break;
            }
            case 6: {
                if (state) {
                    led.setColorRGB(0, 255, 0, 0);
                } else {
                    led.setColorRGB(0, 255, 0, 255);
                }
                break;
            }
            case 7: {
                if (state) {
                    led.setColorRGB(0, 255, 0, 0);
                } else {
                    led.setColorRGB(0, 0, 255, 0);
                }
                break;
            }
            case 8: {
                if (state) {
                    led.setColorRGB(0, 255, 0, 0);
                } else {
                    led.setColorRGB(0, 255, 255, 255);
                }
                break;
            }
            case 9: {
                if (state) {
                    led.setColorRGB(0, 255, 0, 0);
                } else {
                    led.setColorRGB(0, 0, 255, 0);
                }
                break;
            }
            case 10: {
                if (state) {
                    led.setColorRGB(0, 255, 0, 0);
                } else {
                    led.setColorRGB(0, 255, 255, 255);
                }
                break;
            }
            default: {
                break;
            }
        }
        state = !state;
        last_update = millis();
    }
}