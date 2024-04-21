#include <SoftwareSerial.h>
SoftwareSerial Screen(10, 11);
unsigned char Buffer[9];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Screen.begin(115200);
 
}
void loop() {
  int j = 10;
  for(int i=0; i < 100; i++){
    
    SCREEN_Write(0x10 , i);
    delay(1000);
    SCREEN_Write(0x20, j);
    SCREEN_Write(0x30, i+1);
    SCREEN_Write(0x40, j*10);
    delay(1000);
    Serial.println("i-"+String(i)+"   j-"+String(j));
    j = j + 1;
  }

}