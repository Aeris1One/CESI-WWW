#include <Arduino.h>
#include <Wire.h>
#include <math.h>

float get_pressure(){
    
    const int brocheCapteur = A0;                               // Définition des broches de connexion du capteur
    int valeurCapteur = analogRead(brocheCapteur);              // Lecture de la valeur du capteur
    float pression = valeurCapteur * 25 / 1023;                 // Conversion de la valeur du capteur en pression

    //Serial.println(pression);                                   // Affichage de la valeur de la pression

    delay(1000);
    return pression;
}