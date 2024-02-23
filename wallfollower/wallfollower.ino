//   WALL FOLLOWING ROBOT

#include "Adafruit_VL53L0X.h" //Importing the range sensor library

#define lf 4
#define lb 5
#define rf 7
#define rb 8
#define en1 3
#define en2 9

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  // put your setup code here, to run once:
  pinMode(lf, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rb, OUTPUT);


  Serial.begin(9600);

while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  lox.startRangeContinuous(); //Start the range sensor
}

  int a = 100;
void loop() {

  if (lox.isRangeComplete()) {
    
    float distance = lox.readRange()/10; //calculate distance in cm

    if (distance > 10 && distance < 15){
      forward(a+50);
    }
    if (distance <= 10){
      right(a-35);
    }
    if (distance >= 15){
      left(a-35);
    }
  }


  }
