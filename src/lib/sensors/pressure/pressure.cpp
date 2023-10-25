#include <Arduino.h>                                            // Initialisation des différentes bibliothèques 
#include <Wire.h>
#include <math.h>
#include <BME280I2C.h> 

BME280I2C bme;
bme.begin();

float get_pressure(){                                          
    
    const int broche_capteur = A0;                              // Définition des broches de connexion du capteur
    int valeur_capteur = bme.read(pres) ;                       // Lecture de la valeur du capteur
    float pression = valeur_capteur * 25 / 1023;                // Conversion de la valeur du capteur en pression

    delay(1000);
    return pression;
}