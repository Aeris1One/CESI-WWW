#include <lib/globals.h>
#include <lib/config/config.h>
#include <lib/carte SD/carte SD.h>
#include <lib/sensors/hygrometry/hygrometry.h>
#include <lib/sensors/temperature/temperature.h>
#include <lib/sensors/luminosity/luminosity.h>
#include <lib/sensors/pressure/pressure.h>
#include <lib/sensors/RTC/horloge.h>
#include <lib/sensors/GPS/gps.h>

void mtn_setup(){
    mode=4;
    //led.setColorRGB(0, 255, 165, 0);
}

void mtn_loop(){

    if(timer >= get_LOG_INTERVAL()*10){
        Serial.println(get_horloge(), get_luminosity(), get_temperature(), get_hygrometry(), get_pressure(), get_gps());
        timer = 0;
    }
}