#include <Arduino.h>
#include <ChainableLED.h>
#include <lib/output/led.h>
#include <lib/globals.h>
#include <EEPROM.h>
#include <Wire.h>
#include <EEPROM.h>


#define EEPROM_LOG_INTERVAL_ADDR 0
#define EEPROM_FILE_MAX_SIZE_ADDR 2
#define EEPROM_RESET_FLAG_ADDR 4
#define EEPROM_TIMEOUT_ADDR 5
#define EEPROM_LUMIN_ADDR 10
#define EEPROM_LUMIN_LOW_ADDR 11
#define EEPROM_LUMIN_HIGH_ADDR 13
#define EEPROM_TEMP_AIR_ADDR 15
#define EEPROM_MIN_TEMP_AIR_ADDR 16
#define EEPROM_MAX_TEMP_AIR_ADDR 18
#define EEPROM_HYGR_ADDR 20
#define EEPROM_HYGR_MINT_ADDR 21
#define EEPROM_HYGR_MAXT_ADDR 23
#define EEPROM_PRESSURE_ADDR 25
#define EEPROM_PRESSURE_MIN_ADDR 26
#define EEPROM_PRESSURE_MAX_ADDR 28


int logInterval;
int fileMaxSize;
int resetFlag;
int timeout;
int luminosity;
int luminLowThreshold;
int luminHighThreshold;
int tempAir;
int minTempAir;
int maxTempAir;
int hygrometry;
int hygrMinTemp;
int hygrMaxTemp;
int pressure;
int pressureMin;
int pressureMax;

void readEEPROMData() {

  logInterval = EEPROM.read(EEPROM_LOG_INTERVAL_ADDR);
  fileMaxSize = EEPROM.read(EEPROM_FILE_MAX_SIZE_ADDR);
  resetFlag = EEPROM.read(EEPROM_RESET_FLAG_ADDR);
  timeout = EEPROM.read(EEPROM_TIMEOUT_ADDR);
  luminosity = EEPROM.read(EEPROM_LUMIN_ADDR);
  luminLowThreshold = EEPROM.read(EEPROM_LUMIN_LOW_ADDR);
  luminHighThreshold = EEPROM.read(EEPROM_LUMIN_HIGH_ADDR);
  tempAir = EEPROM.read(EEPROM_TEMP_AIR_ADDR);
  minTempAir = EEPROM.read(EEPROM_MIN_TEMP_AIR_ADDR);
  maxTempAir = EEPROM.read(EEPROM_MAX_TEMP_AIR_ADDR);
  hygrometry = EEPROM.read(EEPROM_HYGR_ADDR);
  hygrMinTemp = EEPROM.read(EEPROM_HYGR_MINT_ADDR);
  hygrMaxTemp = EEPROM.read(EEPROM_HYGR_MAXT_ADDR);
  pressure = EEPROM.read(EEPROM_PRESSURE_ADDR);
  pressureMin = EEPROM.read(EEPROM_PRESSURE_MIN_ADDR);
  pressureMax = EEPROM.read(EEPROM_PRESSURE_MAX_ADDR);

}

void processCommand(String command) {

  int equalsIndex = command.indexOf('=');

  if (equalsIndex != -1) {
    String cmdName = command.substring(0, equalsIndex);
    String cmdValue = command.substring(equalsIndex + 1);

    if (cmdName == "LOG_INTERVAL") {

      logInterval = cmdValue.toInt();
      EEPROM.write(EEPROM_LOG_INTERVAL_ADDR, logInterval);

    } else if (cmdName == "FILE_MAX_SIZE") {

      fileMaxSize = cmdValue.toInt();
      EEPROM.write(EEPROM_FILE_MAX_SIZE_ADDR, fileMaxSize);

    } else if (cmdName == "RESET") {

      resetFlag = cmdValue.toInt();
      EEPROM.write(EEPROM_RESET_FLAG_ADDR, resetFlag);

    } else if (cmdName == "TIMEOUT") {

      timeout = cmdValue.toInt();
      EEPROM.write(EEPROM_TIMEOUT_ADDR, timeout);

    } else if (cmdName == "LUMIN") {

      luminosity = cmdValue.toInt();
      EEPROM.write(EEPROM_LUMIN_ADDR, luminosity);

    } else if (cmdName == "LUMIN_LOW") {

      luminLowThreshold = cmdValue.toInt();
      EEPROM.write(EEPROM_LUMIN_LOW_ADDR, luminLowThreshold);

    } else if (cmdName == "LUMIN_HIGH") {

      luminHighThreshold = cmdValue.toInt();
      EEPROM.write(EEPROM_LUMIN_HIGH_ADDR, luminHighThreshold);

    } else if (cmdName == "TEMP_AIR") {

      tempAir = cmdValue.toInt();
      EEPROM.write(EEPROM_TEMP_AIR_ADDR, tempAir);

    } else if (cmdName == "MIN_TEMP_AIR") {

      minTempAir = cmdValue.toInt();
      EEPROM.write(EEPROM_MIN_TEMP_AIR_ADDR, minTempAir);

    } else if (cmdName == "MAX_TEMP_AIR") {

      maxTempAir = cmdValue.toInt();
      EEPROM.write(EEPROM_MAX_TEMP_AIR_ADDR, maxTempAir);

    } else if (cmdName == "HYGR") {

      hygrometry = cmdValue.toInt();
      EEPROM.write(EEPROM_HYGR_ADDR, hygrometry);

    } else if (cmdName == "HYGR_MINT") {

      hygrMinTemp = cmdValue.toInt();
      EEPROM.write(EEPROM_HYGR_MINT_ADDR, hygrMinTemp);

    } else if (cmdName == "HYGR_MAXT") {

      hygrMaxTemp = cmdValue.toInt();
      EEPROM.write(EEPROM_HYGR_MAXT_ADDR, hygrMaxTemp);

    } else if (cmdName == "PRESSURE") {

      pressure = cmdValue.toInt();
      EEPROM.write(EEPROM_PRESSURE_ADDR, pressure);

    } else if (cmdName == "PRESSURE_MIN") {

      pressureMin = cmdValue.toInt();
      EEPROM.write(EEPROM_PRESSURE_MIN_ADDR, pressureMin);

    } else if (cmdName == "PRESSURE_MAX") {

      pressureMax = cmdValue.toInt();
      EEPROM.write(EEPROM_PRESSURE_MAX_ADDR, pressureMax);

    }
  }
}


void setup() {
  Serial.begin(9600); 
  readEEPROMData(); 
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    processCommand(command);
  }


}

