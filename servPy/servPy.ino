#include <Servo.h>

Servo serv;

String dataIn, Xdata, Ydata, widthData, heightData;
int Xpos, Ypos, X, Y, widthPos, heightPos, width, height, midX, midY;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
serv.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
  dataIn = Serial.readStringUntil('\r');

  Xpos = dataIn.indexOf(",");
  Xdata = dataIn.substring(0, Xpos);
  X = Xdata.toInt();

  dataIn = dataIn.substring(Xpos+1);

  Ypos = dataIn.indexOf(",");
  Ydata = dataIn.substring(0, Ypos);
  Y = Ydata.toInt();

  dataIn = dataIn.substring(Ypos+1);

  widthPos = dataIn.indexOf(",");
  widthData = dataIn.substring(0, widthPos);
  width = widthData.toInt();

  dataIn = dataIn.substring(widthPos+1);

  heightPos = dataIn.indexOf(",");
  heightData = dataIn.substring(0, heightPos);
  height = heightData.toInt();

  midX = map(X, 0, width, 180, 0);
  Y = map(Y, 0, height, 0, 180);

  serv.write(midX);

}
