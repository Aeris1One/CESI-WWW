//
// Created by charlesp on 25/10/23.
//

#include "luminosity.h"
#include <Arduino.h>

#define LUMINOSITY_PIN A0

int get_luminosity() {
    return analogRead(LUMINOSITY_PIN);
}