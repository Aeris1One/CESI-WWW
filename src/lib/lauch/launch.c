#include <SoftwareSerial.h>
#include <Arduino.h>
#include <input.h>

void launch(){
  delay(5000);
  if(input.red_short_flag_raised()){
    mode = 1
  } else {
    mode = 0
  }
  input.resetFlags();
}