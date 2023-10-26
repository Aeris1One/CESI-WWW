#include <BME280I2C.h>

float get_hygrometry(){
    BME280 bme;
    bme.begin()
    float hygrometry = bme.readHumidity();
    return hygrometry;
}