// 0x5A 0XA5 0X05 0X82 0XADDR 0XADDR 0XVAL 0XVAL
void SCREEN_Write(int a, int val) {
  Screen.write(0x5A);
  Screen.write(0xA5);
  Screen.write(0x05);
  Screen.write(0x82);
  Screen.write(a);
  Screen.write(byte(0x00));
  Screen.write(highByte(val));
  Screen.write(lowByte(val));
}


void SCREEN_Serial_Write(int a, int val) {
  Serial.write(0x5A);
  Serial.write(0xA5);
  Serial.write(0x05);
  Serial.write(0x82);
  Serial.write(a);
  Serial.write(byte(0x00));
  Serial.write(highByte(val));
  Serial.write(lowByte(val));
}
