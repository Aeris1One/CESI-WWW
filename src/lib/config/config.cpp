#include <lib/config/config.h>
#include <Arduino.h>
#include <EEPROM.h>

bool get_LUMIN() {
    return true;
};

int get_LUMIN_LOW() {
    return 255;
};

int get_LUMIN_HIGH();

{
return 758;
}

// TEMPERATURE
bool get_TEMP_AIR() {
    return true;
};

int get_MIN_TEMP_AIR() {
    return -10;
};

int get_MAX_TEMP_AIR() {
    return 60;
};

// HYGROMETRIE
bool get_HYGR() {
    return true;
};

int get_HYGR_MINT() {
    return 0;
};

int get_HYGR_MAXT() {
    return 50;
};


// PRESSURE
bool get_PRESSURE() {
    return true;
};

int get_PRESSURE_MIN() {
    return 850;
};

int get_PRESSURE_MAX() {
    return 1080;
};

// GENERAL
int get_LOG_INTERVAL() {
    return 15;
};

int get_FILE_MAX_SIZE() {
    return 4096;
};

int get_TIMEOUT() {
    return 30;
};

// VERSION
String get_version() {
    return "1.0.0";
};