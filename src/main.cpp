#include <Arduino.h>
#include <lib/input/input.h>
#include "lib/output/led.h"

// Setup Timer Interrupts
#define USE_TIMER_1 true
#define USE_TIMER_2 true

#include <TimerInterrupt.h>

#include <lib/mode/std/std.h>
#include <lib/mode/cfg/cfg.h>
#include <lib/mode/eco/eco.h>
#include <lib/mode/mtn/mtn.h>

#define RED_PIN 4
#define GREEN_PIN 3
#define LED_CIN 5
#define LED_DIN 6

Input input(RED_PIN, GREEN_PIN);
Output output(LED_CIN, LED_DIN);

#include <lib/globals.h>

void timer1_callback() {
    output.update();
    input.update();
    timer += 1;
}

void setup() {
    output.set_mode(5);
    output.update();   

    ITimer1.init();
    ITimer1.attachInterruptInterval(100, timer1_callback); 

    Serial.begin(9600);

    delay(5000);

    if (input.red_short_flag_raised() or input.red_long_flag_raised()) {
        cfg_setup();
    } else {
        std_setup();
    }
}

#include <lib/carte SD/carte SD.h>
#include <RTClib.h>
void loop() {

}
