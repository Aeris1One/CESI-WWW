#include <Arduino.h>
#include <lib/input/input.h>
#include "lib/output/led.h"

// Setup Timer Interrupts
#define USE_TIMER_1 true
#define USE_TIMER_2 true

#include <TimerInterrupt.h>


#define DEBUG 0

#define RED_PIN 4
#define GREEN_PIN 3
#define LED_CIN 5
#define LED_DIN 6

#if DEBUG
#include <avr8-stub.h>
#endif

Input input(RED_PIN, GREEN_PIN);
Output output(LED_CIN, LED_DIN);

#include <lib/globals.h>

void timer1_callback() {
    output.update();
    input.update();
}

void setup() {
#if DEBUG
    debug_init();
    delay(1000);
#endif

    output.set_mode(5);
    output.update();

    ITimer1.init();
    ITimer1.attachInterruptInterval(100, timer1_callback);

    Serial.begin(9600);
}


void loop() {
    Serial.println("Hello, world!");
    Serial.print("Red short : ");
    Serial.println(input.red_short_flag_raised());
    Serial.print("Red long : ");
    Serial.println(input.red_long_flag_raised());
    Serial.print("Green short : ");
    Serial.println(input.green_short_flag_raised());
    Serial.print("Green long : ");
    Serial.println(input.green_long_flag_raised());
    Serial.println("----");
    input.resetFlags();
    delay(1000);
}
