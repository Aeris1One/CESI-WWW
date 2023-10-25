#include <Arduino.h>                                            // Initialisation des différentes bibliothèques 
#include <Wire.h>
#include <math.h>

float get_pressure(){                                          
    
    const int broche_capteur = A0;                              // Définition des broches de connexion du capteur
    int valeur_capteur = analogRead(broche_capteur);            // Lecture de la valeur du capteur
    float pression = valeur_capteur * 25 / 1023;                // Conversion de la valeur du capteur en pression

    //Serial.println(pression);                                 // Affichage de la valeur de la pression

    delay(1000);
    Serial.print(pression);
    return pression;
}