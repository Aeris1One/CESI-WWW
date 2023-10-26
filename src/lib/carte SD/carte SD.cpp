#include <SPI.h>        
#include <SD.h>

#define MAX_FILE_SIZE 2048

void Save_SD(int lum, int temp, int hygr, int pres, int time){          // Valeurs des capteurs necessaire
    if (!SD.begin()){                                                   // Vériication du lancement de la carte SD sans problème
        Serial.println("Erreur lors du lancement de la carte SD");
        return;
    }
    File fichier = SD.open(time + "_0.log");                            // Vérification de la création du fichier
    if (!fichier){
        fichier = SD.open(time + "_0.log",FILE_WRITE);
        if (!fichier){
            Serial.println("Erreur de création du fichier");            // Erreur d'accès au fichier 
            return;
        }
    }
    int taille = fichier.size();                                        // On récupère la taille du fichier avec size()
    if (taille > MAX_FILE_SIZE){                                        // Vérification si le fichier est plein
        int x = 1 ;                                                     // Initialisation de x qui va être la version de notre fichier 
        while (true){
            String nomFichier = String(time) + String(x) +
                                ".log";        // On crée un nouveau fichier avec le nom de la date et l'heure
            File fichierExistant = SD.open(nomFichier);  // Création d'un nouveau fichier car le précédent est plein
            if (!fichierExistant){
                String nomNvFichier = String(time) + String(x) + ".log";
                fichier.rename(nomNvFichier);
                break;
            }
            x++;                                                        // Incrémentation de x de 1 
        }
        String nomFichier2 = String(time) + "_0.log";
        fichier = SD.open(nomFichier2,
                          FILE_WRITE);                 // On utilise le fichier existant car il n'est pas plein
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
    fichier.print(pres);
    fichier.print(";");
    fichier.print(time);
    fichier.println();

    fichier.close();                                                   // On ferme le fichier quand toutes les données sont enregistré
}
