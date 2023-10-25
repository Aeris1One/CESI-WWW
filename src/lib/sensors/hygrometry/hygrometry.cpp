#include <BME280I2C.h>

BME280 bme;
bme.begin()

float get_hygrometry(){
    hygrometry = bme.readHumidity();
    return hygrometry;
}