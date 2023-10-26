#include <Arduino.h>                                    //Ajout des librairies nécessaire 
#include <Wire.h>
#include <BME280I2C.h>


float get_pressure() {
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {               // On test depuis combien de temps la fonction est lancé
        BME280I2C bme;                              

        Wire.begin();

        bme.begin();                                    // Lancement du capteur

        float pressure = bme.pres();                    // Assigne la valeur du capteur à la variable
        if (pressure < 850 or pressure > 1080) {        // On test si les données sont cohérentes ou non 
            return -1;                                  // Données incohérentes
        } else {
            return pressure;                            // Données cohérentes donc on retourne la valeur                                                      
        }
    }
    return -2;                                          // Timeout