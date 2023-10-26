#include <Arduino.h>    //Bibliothèque permettant d'utiliser les instructions en Arduino
#include <BME280I2C.h>
#include <Wire.h>

float get_temperature(){ // On donne le nom de notre fonction pour récupérer les valeurs de température en flottant
    BME280I2C bme;
    unsigned long startTime=millis();
    while (millis()-startTime < TIMEOUT){
        Wire.begin();
        bme.begin();
        
        float temperature=bme.temp();
        if (temperature< -40 or temperature> 85){
            return -1;
        }

        else{

            BME280I2C::TempUnit tempUnit(BME280I2C::TempUnit_Celsius);  
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
