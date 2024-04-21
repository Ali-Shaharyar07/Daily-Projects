#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  analogWrite(6,80);
  lcd.begin(16, 2);
}

void loop() {
  delay(2000);
  float T = dht.readTemperature();
  float H = dht.readHumidity();
  
  lcd.setCursor(0, 0);
  lcd.print(T);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print(H);
  lcd.print("H");
}

