
#include "ThingSpeak.h" //install library for thing speak
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <Wire.h>

char ssid[] = "ROBOTICS_LAB";        // your network SSID (name) 
char pass[] = "PakistaN";    // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;
#define DHTPIN 4
#define DHTTYPE DHT11

unsigned long myChannelNumber =  2442964;
const char * myWriteAPIKey = "T9UW4YIMG7OLH06L";

// Initialize our values
String myStatus = "";

DHT dht(DHTPIN, DHTTYPE);



void setup() {
  Serial.begin(115200);  //Initialize serial

  //WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  dht.begin();
  Wire.begin();
  pinMode(2, OUTPUT);
}

void loop() {

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

 
  Serial.print("Temp: ");
  Serial.print(dht.readTemperature());
  Serial.print("\t\tHumidity: ");
  Serial.print(dht.readHumidity());
  Serial.print("% H");

  // set the fields with the values
  ThingSpeak.setField(1, dht.readTemperature());
  ThingSpeak.setField(2, dht.readHumidity());

  
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
