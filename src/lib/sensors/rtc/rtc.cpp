//
// Created by charlesp on 25/10/23.
//

#include "rtc.h"
#include <Arduino.h>

#define LUMINOSITY_PIN A0

int get_datetime() {
    return analogRead(LUMINOSITY_PIN);
}