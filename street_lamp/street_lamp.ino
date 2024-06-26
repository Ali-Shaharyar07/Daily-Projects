#define ldr 7
#define laser 9           // Declaring the pin numbers for the LDR, laser and relay
const int relayPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(laser, OUTPUT);        //Setting whether the pins are to be OUTPUT to or INPUT from
  pinMode (relayPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(laser, HIGH); // Turning the laser on
  int x = digitalRead(ldr);  // Reading the LDR values
  Serial.println("X: " + String(x));
  if (x == 0 ){         // If laser is detected, then to turn on the relay connected to the pump
  digitalWrite (relayPin, HIGH);
  }else{ digitalWrite (relayPin, LOW);} // Otherwise, turn the relay off

}