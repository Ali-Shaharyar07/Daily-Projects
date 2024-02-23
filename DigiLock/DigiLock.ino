#include <EEPROM.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 4;
const int passLen = 4;
char Data[passLen];
char Master[passLen] = "1234";
char res1[passLen];
char res2[passLen];
char resCheck[passLen] = "****";
int dcount = 1;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
   
}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("Enter PIN: ");
  
  char customKey = customKeypad.getKey();

  if (customKey){
    Serial.println(customKey);
    Data[dcount] = customKey;
    lcd.setCursor(dcount, 1);
    Serial.print("dcount: "+ dcount);
    lcd.print("*");
    dcount += 1;
  }

  if (dcount == passLen){
    lcd.clear();
    if (!strcmp(Data, resCheck)){
        Serial.print("Reset");
    }


    if (!strcmp(Data, Master)){
      Serial.println("Correct");
      lcd.print("Correct!");
      delay(1500);
      int cd = 7;
      while (cd > 0){
        lcd.clear();
        lcd.setCursor(1,1);
        Serial.print("Closing in "+ cd);
        lcd.print("Closing in: " + cd);
        delay(1000);
      }
    }
    else {
      lcd.print("Incorrect");
      Serial.println("Incorrect");
      delay(1550);
    }
    clearData();
    lcd.clear();
  }
  
}



 void clearData(){
  while(dcount != 0){
    Data[dcount] = 0;
    dcount --;
  }
 }
 
 void getCode(){
  
 }