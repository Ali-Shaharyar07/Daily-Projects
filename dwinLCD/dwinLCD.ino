#include <SoftwareSerial.h>
SoftwareSerial Screen(10, 11);
unsigned char Buffer[9];

#include "DHT.h"

#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Screen.begin(115200);
  dht.begin();
}

void loop() {

  SCREEN_Read();

  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F(" %  Temperature: "));
  Serial.print(t);
  Serial.print(F(" °C "));
  Serial.print(f);
  Serial.println(F(" °F "));


  SCREEN_Write(0x10, t * 100);
  SCREEN_Write(17, f * 100);

  SCREEN_Write(81, t * 100);
  SCREEN_Write(82, f * 100);
  SCREEN_Write(85, t * 100);
  SCREEN_Write(86, f * 100);
  SCREEN_Write(89, t * 100);
  SCREEN_Write(96, f * 100);
  SCREEN_Write(99, t * 100);
  SCREEN_Write(100, f * 100);
  SCREEN_Write(103, t * 100);
  SCREEN_Write(104, f * 100);

  SCREEN_Write(21,t);
  SCREEN_Write(112,t);
  

  SCREEN_Write(83, h);
  SCREEN_Write(87, h);
  SCREEN_Write(97, h);
  SCREEN_Write(101, h);
  SCREEN_Write(105, h);
}