String dataIn, thumbData, indexData, middleData, ringData, pinkyData;
int thumbPos, indexPos, middlePos, ringPos, pinkyPos;
void setup() {


  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 dataIn = "13,6,79,X,X,";
 thumbPos = dataIn.indexOf(",");
 thumbData = dataIn.substring(0, thumbPos);
 dataIn = dataIn.substring(thumbPos+1);

 indexPos = dataIn.indexOf(",");
 indexData = dataIn.substring(0, indexPos);
 dataIn = dataIn.substring(indexPos+1);

 middlePos = dataIn.indexOf(",");
 middleData = dataIn.substring(0, middlePos);
 dataIn = dataIn.substring(middlePos+1);

 ringPos = dataIn.indexOf(",");
 ringData = dataIn.substring(0, ringPos);
 dataIn = dataIn.substring(ringPos+1);

 pinkyPos = dataIn.indexOf(",");
 pinkyData = dataIn.substring(0, pinkyPos);
 
 Serial.println("Thumb: "+ thumbData + " "+ "Index: "+ indexData + " "+ "Middle: "+ middleData + " "+ "Ring: "+ ringData + " "+ "Pinky: "+ pinkyData);
 delay(4000);
}
