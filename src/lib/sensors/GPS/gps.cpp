#include <SoftwareSerial.h>
#include <Arduino.h>

char get_gps(){

    SoftwareSerial gpsSerial(4,5);
    Serial.begin(9600);
    gpsSerial.begin(9600);

    while(gpsSerial.available()>0){
        char gps_data=gpsSerial.read();
        Serial.print(gps_data);

    }
}

