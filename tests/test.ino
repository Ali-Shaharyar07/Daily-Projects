void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.println(String(digitalRead(8)) + "   " + String(digitalRead(9)) + "  " + String(digitalRead(10)) + "   " + String(digitalRead(11)) + "  " + String(digitalRead(12)));
}