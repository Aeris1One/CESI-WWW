#include <SPI.h>
#include <SD.h>

void Save_SD(int lum, int temp, int hygr, int pres, int time){
    if (!SD.begin()){
        serial.println("Erreur lors du lancement de la carte SD");
        return;
    }
    File fichier = SD.open("YYMMDD_0.log");
    if (!fichier){
        fichier = SD.open("YYMMDD_0.log",FILE_WRITE);
        if (!fichier){
            Serial.println("Erreur de création du fichier");
            return ;
        }
    }
    int taille = fichier.size(),
    if (taille > MAX_FILE_SIZE){
        int x = 1 ;
        while (true){
            File fichierExistant = SD.open("YYMMDD" + string(x) + ".log");
            if (!fichierExistant){
                fichier.rename("YYMMDD" + string(x) + ".log");
                break;
            }
            x++;
        }
        fichier = SD.open("YYMMDD_0.log", FILE_WRITE);
         if (!fichier) {
            Serial.println("Erreur de création de fichier");
            return;
            }
    }
    fichier.print(lum);
    fichier.print(";");
    fichier.print(temp);
    fichier.print(";");
    fichier.print(hygr);
    fichier.print(";");
    fichier.print(press);
    fichier.print(";");
    fichier.print(time);
    fichier.println();

    fichier.close();
}
