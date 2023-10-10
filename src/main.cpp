#include <Arduino.h>
#include <lib/input/input.h>
#include <lib/output/output.h>

#define RED_PIN 8
#define GREEN_PIN 9
#define LED_CIN 4
#define LED_DIN 5

Input input(RED_PIN, GREEN_PIN);
Output output(LED_CIN, LED_DIN);

void setup() {
    Serial.begin(9600);
    output.set_mode(0);
    while (millis() < 5000) {
        Serial.println(millis());
        input.update();
        if (input.is_red_pressed()) {
            output.set_mode(2);
            return;
        }
        if (input.is_green_pressed()) {
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
        Serial.println("Red pressed for 5 secs");
        output.set_mode(4);
        return;
    }
}