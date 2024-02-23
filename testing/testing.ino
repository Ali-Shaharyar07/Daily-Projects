#define lb 2
#define lf 3
#define rb 4
#define rf 7

#define enL 5
#define enR 6

void setup() {
  // put your setup code here, to run once:
pinMode(rf, OUTPUT);
pinMode(rb, OUTPUT);
pinMode(lf, OUTPUT);
pinMode(lb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(rb, HIGH);
analogWrite(enL, 255);
analogWrite(enR, 255);
}
