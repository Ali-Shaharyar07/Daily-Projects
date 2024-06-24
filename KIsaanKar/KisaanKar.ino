#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bt(10, 11);
Servo s1;
Servo s2;
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
  pinMode(rb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay, HIGH);
  s1.attach(12);
  s1.write(180);
  s2.attach(13);
  s2.write(180);
  digitalWrite(lb, LOW);
  digitalWrite(rb, LOW);
  digitalWrite(rf, LOW);
  digitalWrite(lf, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
    m = analogRead(ms);
    m = map(m, 260, 600, 100, 0);
    //Serial.println("m: "+ String(m));
    if(m>0){
       bt.println("*m"+ String(m) + "*");
    }
    delay(100);
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

      case 'S':
      s2.write(0);
      break;

      case 'D':
      s2.write(180);
      break;

       case 'v':
      s1.write(50);
      break;

      case 'c':
      s1.write(180);
      break;
    }
    delay(100);
}
}