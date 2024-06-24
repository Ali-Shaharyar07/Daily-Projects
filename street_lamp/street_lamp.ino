#define ldr 7
#define laser 9
const int relayPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(laser, OUTPUT);
  pinMode (relayPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(laser, HIGH);
  int x = digitalRead(ldr);
  Serial.println("X: " + String(x));
  if (x == 0 ){
  digitalWrite (relayPin, HIGH);
  }else{ digitalWrite (relayPin, LOW);}

}