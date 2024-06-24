#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bt(10, 11);
Servo s1;

#define rb 3
#define rf 4
#define lb 7
#define lf 8
#define en 5
#define en2 6
#define relay 2
#define ms A1
char data;
int n, p, k, m, l = 584, u = 263,  i = 10;


void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);
  pinMode(lb, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
     m = analogRead(ms);
      m = map(m, 260, 600, 100, 0);
    //Serial.println("m: "+ String(m));
    bt.println("*m"+ String(m) + "*");
  
 
  if(bt.available()){
    data = bt.read();
    Serial.println(data);
   
    switch(data){
      case '0':
      stop(0);
      break;

      case '1':
      forward(170);
      break;

      case '2':
      right(170);
      break;

      case '3':
      backward(170);
      break;

      case '4':
      left(170);
      break;
      
      case 'W':
      digitalWrite(relay, LOW);
      break;

      case 'E':
      digitalWrite(relay, HIGH);
      break;

    }
}
}