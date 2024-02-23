const int LF = 2;
const int LB = 4;
const int LS = 3;
const int RF = 5;
const int RB = 7;
const int RS = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LS, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(RS, OUTPUT);
  analogWrite(LS, 255);
  analogWrite(RS, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(500);
  backward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
}
void forward() {
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
}
void backward() {
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
}
void left() {
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
}
void right() {
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
}
