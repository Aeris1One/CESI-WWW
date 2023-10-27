#include <lib/globals.h>
#include <lib/config/config.h>
#include <lib/carte SD/carte SD.h>
#include <lib/sensors/hygrometry/hygrometry.h>
#include <lib/sensors/temperature/temperature.h>
#include <lib/sensors/luminosity/luminosity.h>
#include <lib/sensors/pressure/pressure.h>
#include <lib/sensors/RTC/horloge.h>
#include <lib/sensors/GPS/gps.h>
#include <RTClib.h>

void mtn_setup(){
    mode=4;
    //led.setColorRGB(0, 255, 165, 0);
}

void mtn_loop(){

    if(timer >= get_LOG_INTERVAL()*10){
        Serial.print(get_horloge().timestamp());
        Serial.print(get_luminosity());
        Serial.print(get_temperature());
        Serial.print(get_hygrometry());
        Serial.print(get_pressure());
        Serial.println(get_gps());
        timer = 0;
    }
}