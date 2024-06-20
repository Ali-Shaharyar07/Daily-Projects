#include <Servo.h>
Servo s1;

#define D A1
#define U A2// more light = lower reading   +-100 margin    high reading = less light


int uR, dR;
int pos = 127;
bool margin;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
s1.attach(9);
s1.write(pos);

}

void loop() {
 delay(10);
  // put your main code here, to run repeatedly:
reading();
margin = marginCheck(uR, dR);
Serial.println("U: " + String(uR) + "  D: " + String(dR) + " Margin: " + String(margin) + " pos: " + String(pos));
while(!margin){
  if(dR > uR){
    pos+= 1;
    if(pos>180){pos = 180;}
    Serial.println("inc");
    s1.write(pos);
  } else{
     pos-= 1;
     if(pos<0){pos = 0;}
     Serial.println("dec");
    s1.write(pos);
  }
  reading();
  margin = marginCheck(uR, dR);
  delay(10);
}
}

bool marginCheck(int a, int b){
  if (abs(a-b) <= 200){
    return true;
  } else {return false;}
}

void reading(){
  uR = analogRead(U);
  dR = analogRead(D);
}
