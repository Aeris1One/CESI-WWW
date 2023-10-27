#include <TinyGPS.h>
#include <SoftwareSerial.h>

TinyGPS gps;
SoftwareSerial gpsSerial(3, 4);

String get_gps(){

    gpsSerial.begin(4800);
    bool data_renew = false;
    unsigned short sentences, failed;
    unsigned long characters;

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (gpsSerial.available())
    {
        characters = gpsSerial.read();
        if (gps.encode(characters));
        data_renew = !data_renew;
    }
  }

  if (data_renew) {
    float lat, lon;
    unsigned long age;
    gps.f_get_position(&lat, &lon, &age);
    Serial.print("LAT=");
    Serial.print(lat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : lat, 6);
    Serial.print(" LON=");
    Serial.print(lon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : lon, 6);
  }
  
  if (characters == 0);
    Serial.println("Aucune donnée");

}
