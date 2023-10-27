#include <SPI.h>
#include <SdFat.h>
#include <RTClib.h>

#define MAX_FILE_SIZE 2048

void Save_SD(DateTime time, int lum, int temp, int hygr, int pres, String gps_data) {
    SdFat32 sd;
    File32 file;

    // Filename = YYMMDD_0.log
    String filename_base = String(time.year(), DEC) + String(time.month(), DEC) + String(time.day(), DEC);
    String filename_zero = filename_base + String("_0.log");
    Serial.print("1 : ");
    Serial.println(filename_base);

    if (!sd.begin(4, SPI_HALF_SPEED)) {
        Serial.println("Error initializing SD card");
        return;
    }

    file = sd.open(filename_base + String("_0.log"), FILE_WRITE);

    if (file.size() > 2048) {
        //Serial.println("File too big, renaming");
        int x = 1;
        String filename_loop = filename_base + String("_") + String(x) + String(".log");
        while (sd.exists(filename_loop)) {
            x++;
            filename_loop = filename_base + String("_") + String(x) + String(".log");
            Serial.println(filename_loop);
        }
        //Serial.print("New filename: ");
        //Serial.println(filename_loop);
        char filename_buf[filename_loop.length() + 1];
        filename_loop.toCharArray(filename_buf, filename_loop.length() + 1);
        file.rename(filename_buf);
        file.close();
        file = sd.open(filename_base + String("_0.log"), FILE_WRITE);
    }

    if (!file) {
        Serial.println("Error opening file");
        return;
    }
    //Serial.println("Writing to file");

    String line = String(time.timestamp()) + String(";")
                  + String(lum) + String(";")
                  + String(temp) + String(";")
                  + String(hygr) + String(";")
                  + String(pres) + String(";")
                  + gps_data;
    file.println(line);
    //Serial.print("Wrote: ");
    //Serial.println(line);
    file.close();
    //Serial.println("Done");
}
