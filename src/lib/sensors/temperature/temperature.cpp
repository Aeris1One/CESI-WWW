#include <Arduino.h>    //Bibliothèque permettant d'utiliser les instructions en Arduino
#include <Wire.h>       //Bibliothèque permettant de se connecter au capteur

float get_temperature(){ // On donne le nom de notre fonction pour récupérer les valeurs de température en flottant
    
        int broche= A5;// On spécifie sur quelle broche on décide de placer notre capteur
        int lecture_val_capteur=analogRead(broche);
        float temperature=lecture_val_capteur ;

        delay(1000);
        Serial.print("La température est de :");
        Serial.print(temperature);
        Serial.print(" °C");
    
    return(temperature);
}

//Pas sur que ça fonctionne car j'ai cru voir qu'il fallait utiliser une bibliothèque type adafruit.