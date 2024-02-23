#include <SoftwareSerial.h> //library for software serial
SoftwareSerial bt(11, 10); // RX on Pin 8, TX on Pin 9 (Change these as required!)

char data_in; // data received from serial link
const int Max = 255;

// Motor Connections
const int LF = 5;     // Left Forward
const int LS = 3;     // Left Speed
const int LB = 4;     // Left Backward
const int RF = 6;     // Right Forward
const int RS = 9;     // Right Speed
const int RB = 7;     // Right Backward

void setup() {

  bt.begin(9600); //Change baud rate as required!
  Serial.begin(9600);
  pinMode(LF , OUTPUT);
  pinMode(LB , OUTPUT);
  pinMode(LS , OUTPUT);
  pinMode(RF , OUTPUT);
  pinMode(RB , OUTPUT);
  pinMode(RS , OUTPUT);
  analogWrite(LS, 0);
  analogWrite(RS, 0);
}

void loop() {

  /////////////   Receive and Process Data

  if (bt.available()){
    data_in=bt.read();  //Get next character 
    Serial.println(data_in);
    if(data_in=='R'){ //Button Pressed  // 82
      //<--- Insert button pressed code here 
      analogWrite(LS, Max);
      analogWrite(RS, Max);
      right();
    }
    if(data_in=='L'){ //Button Pressed // 76
      //<--- Insert button pressed code here 
      analogWrite(LS, Max);
      analogWrite(RS, Max);
      left();
    }
    if(data_in=='F') {
      analogWrite(LS, Max);
      analogWrite(RS, Max);
      forward();
    }
    if(data_in=='B') {
      analogWrite(LS, Max);
      analogWrite(RS, Max);
      backward();
    }
    if(data_in=='A') {
      analogWrite(LS, 0);
      analogWrite(RS, 0);
      stop();
    }
  }
}

void forward() {
  digitalWrite(LF , HIGH);
  digitalWrite(LB , LOW);
  digitalWrite(RF , HIGH);
  digitalWrite(RB , LOW);
}

void backward() {
  digitalWrite(LF , LOW);
  digitalWrite(LB , HIGH);
  digitalWrite(RF , LOW);
  digitalWrite(RB , HIGH);
}

void right() {
  digitalWrite(LF , HIGH);
  digitalWrite(LB , LOW);
  digitalWrite(RF , LOW);
  digitalWrite(RB , HIGH);
}

void left() {
  digitalWrite(LF , LOW);
  digitalWrite(LB , HIGH);
  digitalWrite(RF , HIGH);
  digitalWrite(RB , LOW);
}

void stop() {
  digitalWrite(LF , LOW);
  digitalWrite(LB , LOW);
  digitalWrite(RF , LOW);
  digitalWrite(RB , LOW);
}