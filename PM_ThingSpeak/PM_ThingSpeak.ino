
#include "ThingSpeak.h" //install library for thing speak
#include <ESP8266WiFi.h>
#include <Wire.h>
#include "Adafruit_PM25AQI.h"
#include <SoftwareSerial.h>

char ssid[] = "MTGazette";        // your network SSID (name) 
char pass[] = "delta173";    // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;


unsigned long myChannelNumber =  2482731;
const char * myWriteAPIKey = "UV38RUJ6KSOCYGHR";

// Initialize our values
String myStatus = "";

SoftwareSerial pmSerial(4, 3);

Adafruit_PM25AQI aqi = Adafruit_PM25AQI();

void setup() {
  Serial.begin(115200);  //Initialize serial
  delay(1000);
   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  //pmSerial.begin(9600);
  Wire.begin();
}

void loop() {
  PM25_AQI_Data data;
  aqi.read(&data);
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      digitalWrite(2, LOW);
      delay(100);
      digitalWrite(2, HIGH);
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
    digitalWrite(2, LOW);
  }

 
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_env); 
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_env);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_env);

  Serial.print(F("Particles > 0.3um / 0.1L air:")); Serial.println(data.particles_03um); 

  Serial.print(F("Particles > 1.0um / 0.1L air:")); Serial.println(data.particles_10um);

  Serial.print(F("Particles > 2.5um / 0.1L air:")); Serial.println(data.particles_25um);
  
  Serial.print(F("Particles > 5.0um / 0.1L air:")); Serial.println(data.particles_50um);

  Serial.print(F("Particles > 10 um / 0.1L air:")); Serial.println(data.particles_100um);
  

  // set the fields with the values
  ThingSpeak.setField(1, data.pm10_env);
  ThingSpeak.setField(2, data.pm25_env);
  ThingSpeak.setField(3, data.pm100_env);
  ThingSpeak.setField(4, data.particles_03um);
  ThingSpeak.setField(5, data.particles_10um);
  ThingSpeak.setField(6, data.particles_25um);
  ThingSpeak.setField(7, data.particles_50um);
  ThingSpeak.setField(8, data.particles_100um);


  
  // set the status
  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
 
  delay(2000); // Wait 20 seconds to update the channel again
}
