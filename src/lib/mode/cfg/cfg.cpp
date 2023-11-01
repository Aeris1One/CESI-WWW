#include <Arduino.h>
#include <EEPROM.h>

struct Configuration {
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
  //add clock
  //add date
  String day;
};

#define EEPROM_CONFIG_ADDR 0

Configuration config;

void defaultEEPROMData() {
  config.logInterval = 10;
  config.fileMaxSize = 4096;
  config.resetFlag = 0;
  config.timeout = 30;
  config.luminosity = 1;
  config.luminLowThreshold = 255;
  config.luminHighThreshold = 768;
  config.tempAir = 1;
  config.minTempAir = -10;
  config.maxTempAir = 60;
  config.hygrometry = 1;
  config.hygrMinTemp = 0;
  config.hygrMaxTemp = 50;
  config.pressure = 1;
  config.pressureMin = 850;
  config.pressureMax = 1080;

  EEPROM.put(EEPROM_CONFIG_ADDR, config);
}

void readEEPROMData() {
  EEPROM.get(EEPROM_CONFIG_ADDR, config);
}

void processCommand(String command) {
  int equalsIndex = command.indexOf('=');

  if (equalsIndex != -1) {
    String cmdName = command.substring(0, equalsIndex);
    String cmdValue = command.substring(equalsIndex + 1);

    if (cmdName == "LOG_INTERVAL") {
      config.logInterval = cmdValue.toInt();
    } else if (cmdName == "FILE_MAX_SIZE") {
      config.fileMaxSize = cmdValue.toInt();
    } else if (cmdName == "TIMEOUT") {
      config.timeout = cmdValue.toInt();
    } else if (cmdName == "LUMIN") {
      config.luminosity = cmdValue.toInt();
    } else if (cmdName == "LUMIN_LOW") {
      config.luminLowThreshold = cmdValue.toInt();
    } else if (cmdName == "LUMIN_HIGH") {
      config.luminHighThreshold = cmdValue.toInt();
    } else if (cmdName == "TEMP_AIR") {
      config.tempAir = cmdValue.toInt();
    } else if (cmdName == "MIN_TEMP_AIR") {
      config.minTempAir = cmdValue.toInt();
    } else if (cmdName == "MAX_TEMP_AIR") {
      config.maxTempAir = cmdValue.toInt();
    } else if (cmdName == "HYGR") {
      config.hygrometry = cmdValue.toInt();
    } else if (cmdName == "HYGR_MINT") {
      config.hygrMinTemp = cmdValue.toInt();
    } else if (cmdName == "HYGR_MAXT") {
      config.hygrMaxTemp = cmdValue.toInt();
    } else if (cmdName == "PRESSURE") {
      config.pressure = cmdValue.toInt();
    } else if (cmdName == "PRESSURE_MIN") {
      config.pressureMin = cmdValue.toInt();
    } else if (cmdName == "PRESSURE_MAX") {
      config.pressureMax = cmdValue.toInt();
    } else if (cmdName == "RESET") {
      defaultEEPROMData();
    } else if (cmdName == "CLOCK") {
      // Write HOURS-MIN-SECONDS
    } else if (cmdName == "DATE") {
      // Write MM/JJ/YYYY
    } else if (cmdName == "DAY") {
      config.day = cmdValue;
    }

    EEPROM.put(EEPROM_CONFIG_ADDR, config);
  }
}

void setup() {
  Serial.begin(9600);
  defaultEEPROMData();
  readEEPROMData();
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    processCommand(command);
  }
}
