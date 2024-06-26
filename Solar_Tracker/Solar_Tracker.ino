#include <Servo.h> // Including servo library
Servo s1;

#define D A1  // Declaring pins for the LDRs
#define U A2  // The basis on which our LDRs work is more light = lower reading OR high reading = less light


int uR, dR;
int pos = 127; // Setting a default position
bool margin;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
s1.attach(9);
s1.write(pos);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(10);
  reading();      //Calling a function to read the LDRs 
  margin = marginCheck(uR, dR); // Calling a function to check whether the measured values are within a certain range of each other
  Serial.println("U: " + String(uR) + "  D: " + String(dR) + " Margin: " + String(margin) + " pos: " + String(pos));
while(!margin){
  if(dR > uR){ // If they aren't then move accordingly
    pos+= 1;
    if(pos>180){pos = 180;} // This statement is to fix a bug that would try to make the servo move more than 180 degrees
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
  if (abs(a-b) <= 200){ // Here the range is set to 200 (can vary)
    return true;
  } else {return false;}
}

void reading(){
  uR = analogRead(U);
  dR = analogRead(D);
}
