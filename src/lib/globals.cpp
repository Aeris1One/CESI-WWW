//
// Created by charlesp on 27/10/23.
//
#include <Arduino.h>
#include <lib/input/input.h>
#include <lib/output/led.h>

uint8_t mode = 0;
uint32_t timer = 0;

// Pins
#define RED_PIN 4
#define GREEN_PIN 3
#define LED_CIN 5
#define LED_DIN 6
Input input(RED_PIN, GREEN_PIN);
Output output(LED_CIN, LED_DIN);

// Erreurs
bool RTC_ERROR = false;
bool GPS_ERROR = false;
bool SD_ERROR = false;
bool SD_FULL = false;
bool SENSOR_ERROR = false;
bool SENSOR_VALUE_ERROR = false;