#include <Arduino.h>
#include <ChainableLED.h>
#include <lib/output/led.h>
#include <lib/globals.h>
#include <lib...config>

void std_setup(){
    mode=1;
    //led.setColorRGB(0, 0, 255, 0);
}

void std_loop(){

    if(timer >= LOG_INTERVAL*10){
        

        timer = 0;
    }

}