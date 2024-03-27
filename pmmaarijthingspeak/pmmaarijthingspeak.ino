 #include "ThingSpeak.h" //install library for thing speak
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial pmsSerial(D6, D7);

char ssid[] = "ROBOTICS_LAB";        // your network SSID (name) 
char pass[] = "PAKistan";
char ssid2[] = "MTTV 5G";        // your network SSID (name) 
char pass2[] = "bravo173";     // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber =  2482731;
const char * myWriteAPIKey = "04N4KNROQIBKLWVE";
// Initialize our values
String myStatus = "";



void setup() {
  Serial.begin(115200);  //Initialize serial
  pinMode(LED_BUILTIN, OUTPUT);
  // sensor baud rate is 9600
  pmsSerial.begin(9600);
  //WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  Wire.begin();

 if(WiFi.status() != WL_CONNECTED) {
   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);
      WiFi.begin(ssid, pass);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
      digitalWrite(LED_BUILTIN, HIGH);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(3000);  
      
   } 
}
struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};
 
struct pms5003data data;
boolean readPMSdata(Stream *s) {
  if (! s->available()) {
    return false;
  }
  
  // Read a byte at a time until we get to the special '0x42' start-byte
  if (s->peek() != 0x42) {
    s->read();
    return false;
  }
 
  // Now read all 32 bytes
  if (s->available() < 32) {
    return false;
  }
    
  uint8_t buffer[32];    
  uint16_t sum = 0;
  s->readBytes(buffer, 32);
 
  // get checksum ready
  for (uint8_t i=0; i<30; i++) {
    sum += buffer[i];
  }

  uint16_t buffer_u16[15];
  for (uint8_t i=0; i<15; i++) {
    buffer_u16[i] = buffer[2 + i*2 + 1];
    buffer_u16[i] += (buffer[2 + i*2] << 8);
  }
 
  // put it into a nice struct :)
  memcpy((void *)&data, (void *)buffer_u16, 30);
 
  if (sum != data.checksum) {
    //Serial.println("Checksum failure");
    return false;
  }
  // success!
  return true;
}
void loop() {

  // Connect or reconnect to WiFi
 

    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("\nConnected.");
  
  if (readPMSdata(&pmsSerial)){
  // set the fields with the values
  if(data.pm10_env != 0){
    ThingSpeak.setField(1, data.pm10_env);
    ThingSpeak.setField(2, data.pm25_env);
    ThingSpeak.setField(3, data.pm100_env);
    ThingSpeak.setField(4, data.particles_03um);
    ThingSpeak.setField(5, data.particles_10um);
    ThingSpeak.setField(6, data.particles_25um);
    ThingSpeak.setField(7, data.particles_50um);
    ThingSpeak.setField(8, data.particles_100um);
  }
  //Serial.println();
   
   
    // Serial.print("PM 1.0: "); Serial.print(data.pm10_env);
    // Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_env);
    // Serial.print("\t\tPM 10: "); Serial.println(data.pm100_env);
    // Serial.println("---------------------------------------");
    // Serial.print("Particles > 0.3um / 0.1L air:"); Serial.println(data.particles_03um);
    // Serial.print("Particles > 0.5um / 0.1L air:"); Serial.println(data.particles_05um);
    // Serial.print("Particles > 1.0um / 0.1L air:"); Serial.println(data.particles_10um);
    // Serial.print("Particles > 2.5um / 0.1L air:"); Serial.println(data.particles_25um);
    // Serial.print("Particles > 5.0um / 0.1L air:"); Serial.println(data.particles_50um);
    // Serial.print("Particles > 10.0 um / 0.1L air:"); Serial.println(data.particles_100um);
    // Serial.println("---------------------------------------");
  }
  
  // set the status
  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    //Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
 
  delay(20000); // Wait 20 seconds to update the channel again
}
