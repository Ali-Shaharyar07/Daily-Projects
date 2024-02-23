#include <Servo.h>

Servo jawServo;
Servo jawBaseServo;

int a, A, b, B, c, C, jawPos, jawBasePos;

String data, jawData, jawBaseData;
void setup() {
  // put your setup code here, to run once:
jawServo.attach(3);
jawBaseServo.attach(12);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = Serial.readStringUntil('\r');

  a = data.indexOf("a");
  A = data.indexOf("A");
  b = data.indexOf("b");
  B = data.indexOf("B");

  if (a != -1 && A != -1){
    jawPos = (data.substring(a+1, A)).toInt();
    //erial.println("Jaw: "+ String(jawPos));

    jawServo.write(jawPos);
  }
  if (b != -1 && B != -1){
    jawBasePos = (data.substring(b+1, B)).toInt();
    //Serial.println("JawBase: "+ String(jawBasePos));
    jawBaseServo.write(jawBasePos);
  }
}
