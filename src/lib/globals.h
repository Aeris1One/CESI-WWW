//
// Created by charlesp on 25/10/23.
//

#ifndef WWW_GLOBALS_H
#define WWW_GLOBALS_H

#include <Arduino.h>
#include <lib/input/input.h>
#include <lib/output/led.h>

extern uint8_t mode;
extern uint32_t timer;

extern Input input;
extern Output output;

extern bool RTC_ERROR;
extern bool GPS_ERROR;
extern bool SD_ERROR;
extern bool SD_FULL;
extern bool SENSOR_ERROR;
extern bool SENSOR_VALUE_ERROR;

#endif //WWW_GLOBALS_H
