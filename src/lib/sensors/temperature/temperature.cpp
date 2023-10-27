#include <Arduino.h>
#include <BME280I2C.h>
#include <Wire.h>
#include <lib/config/config.h>

float get_temperature(){ // On donne le nom de notre fonction pour récupérer les valeurs de température en flottant
    static BME280I2C bme;
    unsigned long startTime=millis();
    while (millis() - startTime < 5000) {
        Wire.begin();
        bme.begin();
        
        float temperature=bme.temp();
        if (temperature < get_MIN_TEMP_AIR() or temperature > get_MAX_TEMP_AIR()) {
            return -1;
        }

        else{
            return temperature;
        }
        
    }
    
    return -2;
}
        // delay(1000);
        // Serial.print("La température est de :");
        // Serial.print(temperature);
        // Serial.print(" °C");
    
    //return(temperature)
