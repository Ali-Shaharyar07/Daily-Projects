#define lf 4
#define lb 5
#define rf 7
#define rb 8
#define trigf 12
#define echof 13
#define trigb A4
#define echob A3
#define en1 3
#define en2 9


void setup() {
  // put your setup code here, to run once:
  pinMode(lf, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(trigf, OUTPUT);
  pinMode(echof, INPUT);
  pinMode(trigb, OUTPUT);
  pinMode(echob, INPUT);

  Serial.begin(9600);

}
  int a = 100;
void loop() {
  digitalWrite(trigf, LOW);
  delay(10);
  digitalWrite(trigf, HIGH);
  delay(10);
  digitalWrite(trigf, LOW);

  long pulses = pulseIn(echof, HIGH);
  float distance = pulses / 58.4;

  long pulses2 = pulseIn(echob, HIGH);
  float distance2 = pulses2 / 58.4;

  Serial.println(distance);
  if (distance > 10.0 && distance  < 18.0){
    forward(a+10);
  // }
  // if (distance >= 18.0){
  //   left(a-50);
  // }
  // if (distance <= 10.0){
  //   right(a-25);
  // }
  
  if (distance2 > distance) {
    
    right (a);
  }
  if (distance > distance2) {
  
    left (a);
  }
  if (distance2 = distance) {
  
    right (a);
  }
  

  }
