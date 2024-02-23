
#include "DHT.h"

#define DHTPIN 8     
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  

  
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);


  // Compute heat index in Fahrenheit (the default)
  int hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  int hic = dht.computeHeatIndex(t, h, false);
  
  String T = "T"+String(t)+"t";
  String H = "H"+String(h)+"h";
  String F = "F"+String(f)+"f";
  String A = "A"+String(hif)+"a";
  String B = "B"+String(hic)+"b";

  Serial.println(T);
  delay(100);
  Serial.println(H);
  delay(100);
  Serial.println(F);
  delay(100);
  Serial.println(A);
  delay(100);
  Serial.println(B);
  delay(100);
}
