#include <SoftwareSerial.h>

#include "Adafruit_VL53L0X.h"
#include <SoftwareSerial.h>
#define ldr A2
#define rled 2
#define buzzer 3

int dist, light;
String cmd;
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
SoftwareSerial bt(10, 11);
void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);
  Serial.begin(9600);

  pinMode(rled, OUTPUT);
  pinMode(buzzer, OUTPUT);

while (! Serial) {
    delay(1);
  }

  
  if (!lox.begin()) { 
    while(1);
  }  
  // start continuous ranging
  lox.startRangeContinuous();


}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(ldr);
  light = map(light, 0, 1023, 0, 660);
  
  if (lox.isRangeComplete()) {
   
    dist = lox.readRange()/10;
    
    cmd = "*|Dist: "+ String(dist) + " , " + "LDR: " + String(light)+ "*";
    

    Serial.println(cmd);
    if (bt.available()){
      bt.print(cmd);
    }
  }

  if (light < 5){
    digitalWrite(rled, HIGH);

  } else {
    digitalWrite(rled, LOW);
  }
  if (dist < 10 ){
    digitalWrite(buzzer, HIGH);   
  } else {
    digitalWrite(buzzer, LOW);
  }

}
