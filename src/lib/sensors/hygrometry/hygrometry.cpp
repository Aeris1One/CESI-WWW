#include <Arduino.h>
#include <Wire.h>
#include <BME280I2C.h>
#include <lib/config/config.h>


float get_hygrometry() {
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
        static BME280I2C bme;

        Wire.begin();

        bme.begin();

        float hygrometry = bme.hum();
        if (hygrometry < get_HYGR_MINT() || hygrometry > get_HYGR_MAXT()) {
            return -1; // données incohérentes
        } else {
            return hygrometry;
        }
    }
    return -2; // timeout
}