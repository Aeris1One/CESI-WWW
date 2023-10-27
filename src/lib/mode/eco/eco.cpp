#include <lib/globals.h>
#include <lib/config/config.h>
#include <lib/carte SD/carte SD.h>
#include <lib/sensors/hygrometry/hygrometry.h>
#include <lib/sensors/temperature/temperature.h>
#include <lib/sensors/luminosity/luminosity.h>
#include <lib/sensors/pressure/pressure.h>
#include <lib/sensors/RTC/horloge.h>
#include <lib/sensors/GPS/gps.h>

void eco_setup(){
    mode=2;

}

void eco_loop(){

    if(timer >= get_LOG_INTERVAL()*20){
        Save_SD(get_horloge(), get_luminosity(), get_temperature(), get_hygrometry(), get_pressure(), get_gps());
        timer = 0;
    }
}