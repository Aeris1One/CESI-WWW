#include <Arduino.h>
#include <Wire.h>
#include <BME280I2C.h>


float get_hygrometry() {
    unsigned long startTime = millis();
    while (millis() - startTime < TIMEOUT) {
        BME280I2C bme;

        Wire.begin();

        bme.begin();

        float hygrometry = bme.hum();
        if (hygrometry < HYGR_MINT || hygrometry > HYGR_MAXT) {
            return -1; // données incohérentes
        } else {
            return hygrometry;
        }
    }
    return -2; // timeout
}