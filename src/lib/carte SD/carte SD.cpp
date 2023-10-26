#include <SPI.h>
#include <SD.h>

void Save_SD(int lum, int temp, int hygr, int pres, int time){
    if (!SD.begin()){
        serial.println("Erreur lors du lancement de la carte SD");
        return;
    }
    

}
