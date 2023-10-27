//
// Created by charlesp on 26/10/23.
//
#ifndef WWW_CONFIG_H
#define WWW_CONFIG_H

#include <Arduino.h>

// Tried to use a struct, but too complicated to store in eeprom
// so did it this ugly way

// LUMINOSITE
bool get_LUMIN();

void set_LUMIN(bool lumin);

short int get_LUMIN_LOW();

void set_LUMIN_LOW(int lumin_low);

short int get_LUMIN_HIGH();

void set_LUMIN_HIGH(int lumin_high);

// TEMPERATURE
bool get_TEMP_AIR();

void set_TEMP_AIR(bool temp_air);

short int get_MIN_TEMP_AIR();

void set_MIN_TEMP_AIR(int min_temp_air);

short int get_MAX_TEMP_AIR();

void set_MAX_TEMP_AIR(int max_temp_air);

// HYGROMETRIE
bool get_HYGR();

void set_HYGR(bool hygr);

short int get_HYGR_MINT();

void set_HYGR_MINT(int hygr_mint);

short int get_HYGR_MAXT();

void set_HYGR_MAXT(int hygr_maxt);

// PRESSURE
bool get_PRESSURE();

void set_PRESSURE(bool pressure);

short int get_PRESSURE_MIN();

void set_PRESSURE_MIN(int pressure_min);

short int get_PRESSURE_MAX();

void set_PRESSURE_MAX(int pressure_max);

// GENERAL
uint16_t get_LOG_INTERVAL();

void set_LOG_INTERVAL(int log_interval);

short int get_FILE_MAX_SIZE();

void set_FILE_MAX_SIZE(int file_max_size);

short int get_TIMEOUT();

void set_TIMEOUT(int timeout);

// RESET
void reset_config();

// CLOCK
void set_date();

void set_time();

void set_day();

// VERSION
String get_version();

#endif //WWW_CONFIG_H
