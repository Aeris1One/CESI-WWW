//
// Created by charlesp on 03/11/23.
//

#include "sensors.h"
#include <Arduino.h>
//#include <SdFat.h>
#include <globals.h>
#include <BME280I2C.h>
#include <Wire.h>
#include <RTClib.h>

#define LUMIN_PIN A0

void sensors::capture(bool sd, bool gps) {
    bool RTC_ERROR = false;
    bool GPS_ERROR = false;
    bool SENSOR_ERROR = false;
    bool SENSOR_INCOHERENT = false;
    bool SD_FULL = false;
    bool SD_ERROR = false;

    // LUMINOSITY
    int luminosity = analogRead(0);
    if (luminosity < config.getValue("LUMIN_LOW")) {
        luminosity = 0;
    } else if (luminosity < config.getValue("LUMIN_HIGH")) {
        luminosity = 2;
    } else {
        luminosity = 1;
    }

    // TEMPERATURE, HUMIDITY, PRESSURE
    float temperature, humidity, pressure;
    BME280I2C bme;
    Wire.begin();
    if(!bme.begin()) {
        SENSOR_ERROR = true;
        temperature = -32768;
        humidity = -32768;
        pressure = -32768;
    } else {
        temperature = bme.temp();
        humidity = bme.hum();
        pressure = bme.pres();
    }

    // TEMPERATURE
    if (config.getValue("TEMP_AIR") == 0){ // Temperature disabled
        temperature = -32768;
    } else if (
            (temperature != -32768) and
            ((temperature < config.getValue("MIN_TEMP_AIR")) or
            (temperature > config.getValue("MAX_TEMP_AIR"))))
    {
        SENSOR_INCOHERENT = true;
        temperature = -32768;
    }

    // HUMIDITY
    if (config.getValue("HYGR") == 0){ // Hygrometry disabled
        humidity = -32768;
    } else if (
            (humidity != -32768) and
            ((temperature < config.getValue("HYGR_MINT")) or
            (temperature > config.getValue("HYGR_MAXT"))))
    {
        humidity = -32768;
    }

    // PRESSURE
    if (config.getValue("PRESSURE") == 0){ // Pressure disabled
        pressure = -32768;
    } else if (
            (pressure != -32768) and
            ((pressure < config.getValue("PRESSURE_MIN")) or
            (pressure > config.getValue("PRESSURE_MAX"))))
    {
        SENSOR_INCOHERENT = true;
        pressure = -32768;
    }

    // GPS
    String gps_data;
    if (gps) {
        // TODO
        gps_data = "4925.7861N;00105.4226E";
    } else {
        gps_data = "NA";
    }

    // RTC
    RTC_DS1307 rtc;
    if (!rtc.begin()) {
        error |= 1;
    }
    DateTime now = rtc.now();

    // STRING
    String csv_string = "";
    csv_string += now.timestamp(DateTime::TIMESTAMP_FULL) + ";";
    if (luminosity == 0) {
        csv_string += "L;";
    } else if (luminosity == 1) {
        csv_string += "M;";
    } else {
        csv_string += "H;";
    }
    if (temperature == -32768) {
        csv_string += "NA;";
    } else {
        csv_string += String(temperature) + ";";
    }
    if (humidity == -32768) {
        csv_string += "NA;";
    } else {
        csv_string += String(humidity) + ";";
    }
    if (pressure == -32768) {
        csv_string += "NA;";
    } else {
        csv_string += String(pressure) + ";";
    }
    csv_string += gps_data + "\n";


    // SD
    if (sd) {
        // TODO
    } else {
        Serial.print(csv_string);
    }

    // ERROR
    error = 0;
    if (RTC_ERROR) {
        error |= 1;
    }
    if (GPS_ERROR) {
        error |= 2;
    }
    if (SENSOR_ERROR) {
        error |= 4;
    }
    if (SENSOR_INCOHERENT) {
        error |= 8;
    }
    if (SD_FULL) {
        error |= 16;
    }
    if (SD_ERROR) {
        error |= 32;
    }
}

bool sensors::set_rtc(uint32_t timestamp) {
    RTC_DS1307 rtc;
    if (!rtc.begin()) {
        error |= 1;
        return false;
    }
    rtc.adjust(DateTime(timestamp));
    return true;
}