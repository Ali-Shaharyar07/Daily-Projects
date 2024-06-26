#include <SoftwareSerial.h>             // Including libraries for bluetooth and servo
#include <Servo.h>

SoftwareSerial bt(10, 11);
Servo s1;
Servo s2;
#define rb 3
#define rf 4
#define lb 7                     
#define lf 8                       //Defining pin numbers
#define en 5
#define en2 6
#define relay 2
#define ms A1
char data;
int n, p, k, m, l = 584, u = 263,  i = 10;             // Declaring variables for data values (l and u being the lower and upper bound of the moisuture sensor)


void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);
  pinMode(lb, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(rf, OUTPUT);            // Declaring whether the pins are to be OUTPUT to or INPUT from
  pinMode(lf, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay, HIGH);
  s1.attach(12);
  s1.write(180);                 // Setting the servos and relay into their original position
  s2.attach(13);
  s2.write(150);
  digitalWrite(lb, LOW);
  digitalWrite(rb, LOW);
  digitalWrite(rf, LOW);
  digitalWrite(lf, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
    m = analogRead(ms);                        // Reading moisture 
    m = map(m, 260, 600, 100, 0);              // Mapping it onto a 0-100% scale using an estimate from the l and u variables
    //Serial.println("m: "+ String(m));
    if(m>0){
       bt.println("*m"+ String(m) + "*");      // Only sending +ve values to phone to remove bugs caused by voltage fluctuation
    }
    delay(100);
  if(bt.available()){
    data = bt.read();           // Reading the incoming text
    Serial.println(data);
   
    switch(data){               // Testing for each case and performing a corresponding function
      case '0':
      stop(0);
      break;

      case '1':
      forward(120);
      break;

      case '2':
      right(120);
      break;

      case '3':
      backward(120);
      break;

      case '4':
      left(120);
      break;
      
      case 'W':
      digitalWrite(relay, LOW);
      break;

      case 'E':
      digitalWrite(relay, HIGH);
      break;

      case 'S':
      s2.write(120);
      break;

      case 'D':
      s2.write(150);
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