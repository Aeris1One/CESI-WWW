#include <BME280I2C.h>
#include <Wire.h>

float get_hygrometry(){
  BME280I2C bme;
  bme.begin();
  float hygrometry = bme.hum();
  return hygrometry;
}