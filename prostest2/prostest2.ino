#include <Servo.h>
Servo myservo;


String dataIn;
int thumbData, indexData, middleData, ringData, pinkyData;
int thumbPos, indexPos, middlePos, ringPos, pinkyPos;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String dataIn = Serial.readStringUntil('\r')

  thumbPos = dataIn.indexOf(",");
  thumbData = (dataIn.substring(0, thumbPos)).toInt();
  dataIn = dataIn.substring(thumbPos+1);

  indexPos = dataIn.indexOf(",");
  indexData = (dataIn.substring(0, indexPos)).toInt();
  dataIn = dataIn.substring(indexPos+1);

  middlePos = dataIn.indexOf(",");
  middleData = (dataIn.substring(0, middlePos)).toInt();
  dataIn = dataIn.substring(middlePos+1);

  ringPos = dataIn.indexOf(",");
  ringData = (dataIn.substring(0, ringPos)).toInt();
  dataIn = dataIn.substring(ringPos+1);

  pinkyPos = dataIn.indexOf(",");
  pinkyData = (dataIn.substring(0, pinkyPos)).toInt();
  
  
  myservo.write(indexData);
  
}
