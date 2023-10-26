#include <RTClib.h>

DateTime get_horloge(){
    RTC_DS1307 rtc;
    if(!rtc.begin()){ //on initialise rtc sinon il y a une erreur
        return DateTime(0,0,0,0,0,0); //verifier si on peut pas mettre un 31 fevrier comme erreur
    }
    else{
        return rtc.now(); //si l'initialisation se passe bien alors on retourne l'heure actuelle
    }     
}