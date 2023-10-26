#include <SPI.h>        
#include <SD.h>

void Save_SD(int lum, int temp, int hygr, int pres, int time){          // Valeurs des capteurs necessaire
    if (!SD.begin()){                                                   // Vériication du lancement de la carte SD sans problème
        serial.println("Erreur lors du lancement de la carte SD");
        return;
    }
    File fichier = SD.open(time + "_0.log");                            // Vérification de la création du fichier
    if (!fichier){
        fichier = SD.open(time + "_0.log",FILE_WRITE);
        if (!fichier){
            Serial.println("Erreur de création du fichier");            // Erreur d'accès au fichier 
            return ;
        }
    }
    int taille = fichier.size(),                                        // On récupère la taille du fichier avec size()
    if (taille > MAX_FILE_SIZE){                                        // Vérification si le fichier est plein
        int x = 1 ;                                                     // Initialisation de x qui va être la version de notre fichier 
        while (true){
            File fichierExistant = SD.open(time + string(x) + ".log");  // Création d'un nouveau fichier car le précédent est plein
            if (!fichierExistant){
                fichier.rename(time + string(x) + ".log");
                break;
            }
            x++;                                                        // Incrémentation de x de 1 
        }
        fichier = SD.open(time + "_0.log", FILE_WRITE);                 // On utilise le fichier existant car il n'est pas plein
         if (!fichier) {
            Serial.println("Erreur de création de fichier");            // Erreur d'accès au fichier 
            return;
            }
    }

    fichier.print(lum);                                                 // On écrit les valeurs des capteurs dans le fichier 
    fichier.print(";");
    fichier.print(temp);
    fichier.print(";");
    fichier.print(hygr);
    fichier.print(";");
    fichier.print(press);
    fichier.print(";");
    fichier.print(time);
    fichier.println();

    fichier.close();                                                   // On ferme le fichier quand toutes les données sont enregistré
}
