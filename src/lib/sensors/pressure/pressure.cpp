#include <Arduino.h>
#include <Wire.h>
#include <BME280I2C.h>


float get_pressure() {
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
        BME280I2C bme;

        Wire.begin();

        bme.begin();

        float pressure = bme.pres();
        if (pressure < 850 or pressure > 1080) {
            return -1; // données incohérentes
        } else {
            return pressure;
        }
    }
    return -2; // timeout
}