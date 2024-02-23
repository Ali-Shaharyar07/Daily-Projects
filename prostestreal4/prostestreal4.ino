#include <Servo.h>

String dataIn, thumbData, indexData, middleData, ringData, pinkyData;
int thumbPos, indexPos, middlePos, ringPos, pinkyPos, indexServ;

Servo myservo;
void setup() {


  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
 dataIn = Serial.readStringUntil('\r');

 
 thumbPos = dataIn.indexOf(",");
 thumbData = dataIn.substring(0, thumbPos);                //readStringuntil('/n')
 dataIn = dataIn.substring(thumbPos+1);

 indexPos = dataIn.indexOf(",");
 indexData = dataIn.substring(0, indexPos);
 dataIn = dataIn.substring(indexPos+1);
 indexServ = indexData.toInt();
 
 middlePos = dataIn.indexOf(",");
 middleData = dataIn.substring(0, middlePos);
 dataIn = dataIn.substring(middlePos+1);

 ringPos = dataIn.indexOf(",");
 ringData = dataIn.substring(0, ringPos);
 dataIn = dataIn.substring(ringPos+1);

 pinkyPos = dataIn.indexOf(",");
 pinkyData = dataIn.substring(0, pinkyPos);
 
 myservo.write(indexServ);
 delay(100);
 Serial.println(String(indexServ));

}
