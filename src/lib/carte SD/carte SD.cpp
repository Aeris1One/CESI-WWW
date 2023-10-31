#include <SPI.h>
#include <SD.h>
#include <RTClib.h>
#include <lib/globals.h>

#define MAX_FILE_SIZE 2048

String create_filename(short int year, short int month, short int day, short int file_number) {
    return String(year, DEC) + String(month, DEC) + String(day, DEC) + "_" + String(file_number) + ".log";
}

void Save_SD(DateTime time, float lum, float temp, float hygr, float pres, String gps_data) {
    File file;

    if (!SD.begin(4, SPI_HALF_SPEED)) {
        // Serial.println("Error initializing SD card");
        return;
    }

    int file_number = 0;
    while (SD.exists(create_filename(time.year(), time.month(), time.day(), file_number))) {
        file_number++;
    }

    file = SD.open(create_filename(time.year(), time.month(), time.day(), file_number), FILE_WRITE);
    if (!file) {
        // Serial.println("Error opening file");
        SD_ERROR = true;
        return;
    }
    // Serial.println("Writing to file");

    char buffer[256]; // Taille du buffer suffisante pour stocker les données GPS
    int buffer_index = 0;

    // Concaténation des données dans le buffer
    sprintf(buffer, "%ld;%f;%f;%f;%f;%s",
            time.timestamp(), lum, temp, hygr, pres, gps_data.c_str());

    // Écriture des données dans le fichier
    file.println(buffer);
    file.close();
}
