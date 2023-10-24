#include <Arduino.h>
#include <lib/input/input.h>
#include "lib/output/led.h"

#define DEBUG 1

#define RED_PIN 4
#define GREEN_PIN 3
#define LED_CIN 5
#define LED_DIN 6

#if DEBUG

#include <avr8-stub.h>

#endif

Input input(RED_PIN, GREEN_PIN);
Output output(LED_CIN, LED_DIN);


void setup() {
#if DEBUG
    debug_init();
#endif
    delay(1000);
    output.set_mode(0);
    while (millis() < 5000) {
        input.update();
        if (input.is_red_pressed()) {
            output.set_mode(2);
            return;
        }
    }
    output.set_mode(1);
}


void loop() {
    output.update();
    input.update();
    if (input.was_red_pressed_for(5000)) {
        output.set_mode(4);
        return;
    }
}
