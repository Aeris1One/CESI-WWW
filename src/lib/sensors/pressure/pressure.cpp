#include <Arduino.h>                                            // Initialisation des différentes bibliothèques 
#include <Wire.h>
#include <math.h>
#include <BME280.h> 

bme.begin();                                                    // Lancement du capteur 

float get_pressure(){                                          
    
    const int broche_capteur = A0;                              // Définition des broches de connexion du capteur
    float pression = bme.pres() ;                               // Lecture de la valeur du capteur
    delay(1000);
    return pression;                                            // Retour de la valeur de la pression 
}