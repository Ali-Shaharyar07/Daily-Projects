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

int read[4];
int error;
int Kp = 50;

void setup() {
  // put your setup code here, to run once:
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

void loop() {
  // put your main code here, to run repeatedly:

read[0] = digitalRead(l2); 
read[1] = digitalRead(l1); 
read[2] = digitalRead(m); 
read[3] = digitalRead(r1);
read[4] = digitalRead(r2);

if (read[0] == 1 && read[1] == 1 && read[2] == 1 && read[3] == 1 && read[4] == 0){
  error = 4;
}
if (read[0] == 1 && read[1] == 1 && read[2] == 1 && read[3] == 0 && read[4] == 0){
  error = 3;
}
if (read[0] == 1 && read[1] == 1 && read[2] == 1 && read[3] == 0 && read[4] == 1){
  error = 2;
}
if (read[0] == 1 && read[1] == 1 && read[2] == 0 && read[3] == 0 && read[4] == 1){
  error = 1;
}
if (read[0] == 1 && read[1] == 1 && read[2] == 0 && read[3] == 1 && read[4] == 1){
  error = 0;
}
if (read[0] == 1 && read[1] == 0 && read[2] == 0 && read[3] == 1 && read[4] == 1){
  error = -1;
}
if (read[0] == 1 && read[1] == 0 && read[2] == 1 && read[3] == 1 && read[4] == 1){
  error = -2;
}
if (read[0] == 0 && read[1] == 0 && read[2] == 1 && read[3] == 1 && read[4] == 1){
  error = -3;
}
if (read[0] == 0 && read[1] == 1 && read[2] == 1 && read[3] == 1 && read[4] == 1){
  error = -4;
}
//Serial.println(String(error));
//Serial.println(String(read[0]) +" "+ String(read[1]) +" "+ String(read[2]) +" "+ String(read[3]) +" "+ String(read[4]));

if (error == 0){
  forward(255, 255);
}
if (error == 1){
  forward(255, 200);
}
if (error == 2){
  forward(255, 180);
}
if (error == 3){
  rightsharp(170, 170);
}
if (error == 4){
  rightsharp(230, 230);
}
if (error == -1){
  forward(200,255);
}
if (error == -2){
  forward(0, 255);
}
if (error == -3){
  leftsharp(170, 170);
}
if (error == -4){
  leftsharp(230, 230);
}

}
