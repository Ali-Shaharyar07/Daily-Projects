#define l2 8
#define l1 9
#define m 10
#define r1 11
#define r2 12

#define enL 5
#define enR 6

#define lb 2
#define lf 3
#define rb 4
#define rf 7

int read[5];
int error;
int Kp = 50;

void setup() {
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);

  pinMode(l2, INPUT);
  pinMode(l1, INPUT);
  pinMode(m, INPUT);
  pinMode(r1, INPUT);
  pinMode(r2, INPUT);

  Serial.begin(9600);
}

void forward(int leftSpeed, int rightSpeed) {
  analogWrite(enL, leftSpeed);
  analogWrite(enR, rightSpeed);
  digitalWrite(lf, HIGH);
  digitalWrite(lb, LOW);
  digitalWrite(rf, HIGH);
  digitalWrite(rb, LOW);
}

void leftsharp(int leftSpeed, int rightSpeed) {
  analogWrite(enL, leftSpeed);
  analogWrite(enR, rightSpeed);
  digitalWrite(lf, LOW);
  digitalWrite(lb, HIGH);
  digitalWrite(rf, HIGH);
  digitalWrite(rb, LOW);
}

void rightsharp(int leftSpeed, int rightSpeed) {
  analogWrite(enL, leftSpeed);
  analogWrite(enR, rightSpeed);
  digitalWrite(lf, HIGH);
  digitalWrite(lb, LOW);
  digitalWrite(rf, LOW);
  digitalWrite(rb, HIGH);
}

void loop() {
  read[0] = digitalRead(l2); 
  read[1] = digitalRead(l1); 
  read[2] = digitalRead(m); 
  read[3] = digitalRead(r1);
  read[4] = digitalRead(r2);

  // Line following logic
  if (read[0] == 1 && read[1] == 1 && read[2] == 1 && read[3] == 1 && read[4] == 0){
    error = 4;
  } else if (read[0] == 1 && read[1] == 1 && read[2] == 1 && read[3] == 0 && read[4] == 0){
    error = 3;
  } else if (read[0] == 1 && read[1] == 1 && read[2] == 1 && read[3] == 0 && read[4] == 1){
    error = 2;
  } else if (read[0] == 1 && read[1] == 1 && read[2] == 0 && read[3] == 0 && read[4] == 1){
    error = 1;
  } else if (read[0] == 1 && read[1] == 1 && read[2] == 0 && read[3] == 1 && read[4] == 1){
    error = 0;
  } else if (read[0] == 1 && read[1] == 0 && read[2] == 0 && read[3] == 1 && read[4] == 1){
    error = -1;
  } else if (read[0] == 1 && read[1] == 0 && read[2] == 1 && read[3] == 1 && read[4] == 1){
    error = -2;
  } else if (read[0] == 0 && read[1] == 0 && read[2] == 1 && read[3] == 1 && read[4] == 1){
    error = -3;
  } else if (read[0] == 0 && read[1] == 1 && read[2] == 1 && read[3] == 1 && read[4] == 1){
    error = -4;
  }
  digitalWrite(lf, HIGH);
  analogWrite(enL, 255);
  Serial.println(String(read[0]) +" "+ String(read[1]) +" "+ String(read[2]) +" "+ String(read[3]) +" "+ String(read[4]));
}