//    CHROME DINO 

// For this code, the LDR used gives a digital output.

//Including the prebuilt library to control the servos
#include <Servo.h>


//Defining the pins for the LDR ; Change it to whatever pin yours is connected to
#define ldr 4
//Defining the servo 
Servo serv;



void setup() {
  // put your setup code here, to run once:

  serv.attach(9);                     
  pinMode(ldr, INPUT);
  Serial.begin(9600); //Set the baudrate
}

void loop() {
  // put your main code here, to run repeatedly:


  int data = digitalRead(ldr); //Take input from the LDR

  if (data == 1){
    serv.write(50); //Move servo if a change is detected
    delay(10);
    serv.write(0);
  }
  if (data == 0){                                      
    serv.write(0);  //Return to original postion if the change reverts
  }
  
}
