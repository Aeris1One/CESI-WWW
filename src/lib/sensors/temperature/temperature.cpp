#include <Arduino.h>    //Bibliothèque permettant d'utiliser les instructions en Arduino
#include <BME280I2C.h>
#include <Wire.h>

void setup(){
    
    Wire.begin();
    BME280I2C bme;

      while(!bme.begin())
        {
            Serial.println("Nous n'avons pas trouvé le capteur");
            delay(1000);
        }

}  


float get_temperature(){ // On donne le nom de notre fonction pour récupérer les valeurs de température en flottant
    
    BME280I2C bme;
    bme.begin();
        
        float temperature;
        temperature=bme.temp();
        
        BME280I2C::TempUnit tempUnit(BME280I2C::TempUnit_Celsius);  
         
        delay(1000);
        Serial.print("La température est de :");
        Serial.print(temperature);
        Serial.print(" °C");
    
    return(temperature);
}
