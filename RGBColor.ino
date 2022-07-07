//Arduino pins:
#define S0 12
#define S1 9
#define S2 10
#define S3 11
#define sensorOut 8


//Output from the sensor:
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

//Formatted color values:
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

//Values used for calibration
int redMin;
int redMax;
int greenMin;
int greenMax;
int blueMin;
int blueMax;

int color = 0;

void setup() {
 //Declarations:
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);


 pinMode(sensorOut, INPUT);
 // Set frequency scaling to 20%:
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 Serial.begin(9600);//begin serial communication
 calibrate();//calibrate sensor (look at serial monitor)
}

void loop() {
 readColor();//read sensor
 decideColor();//format color values
 printColor();//print values
}

void decideColor() {//format color values
 //Limit possible values:
 redColor = constrain(redColor, 0, 255);
 greenColor = constrain(greenColor, 0, 255);
 blueColor = constrain(blueColor, 0, 255);

 //find brightest color:
 int maxVal = max(redColor, blueColor);
 maxVal = max(maxVal, greenColor);
 //map new values
 redColor = map(redColor, 0, maxVal, 0, 255);
 greenColor = map(greenColor, 0, maxVal, 0, 255);
 blueColor = map(blueColor, 0, maxVal, 0, 255);
 redColor = constrain(redColor, 0, 255);
 greenColor = constrain(greenColor, 0, 255);
 blueColor = constrain(blueColor, 0, 255);

 //light led
 //analogWrite(redLED, redColor);
 Serial.println(redColor);
  Serial.println();
   Serial.println(greenColor);
    Serial.println();
     Serial.println(blueColor);
      Serial.println();

 //decide which color is present (you may need to change some values here):
 if (redColor > 250 && greenColor > 250 && blueColor > 250) {
   color = 1;//white
 }
 else if (redColor < 25 && greenColor < 25 && blueColor < 25) {
   color = 2;//black
 }
 else if (redColor > 200 &&  greenColor > 200 && blueColor < 100) {
   color = 4;//yellow
 }
 else if (redColor > 200 &&  greenColor > 25 /*&& blueColor < 100*/) {
   color = 3;//orange
 }
 else if (redColor > 200 &&  greenColor < 100 && blueColor > 200) {
   color = 5;//purple
 }
 else if (redColor > 250 && greenColor < 200 && blueColor < 200) {
   color = 6;//red
 }
 else if (redColor < 200 && greenColor > 250 && blueColor < 200) {
   color = 7;//green
 }
 else if (redColor < 200 /*&& greenColor < 200*/ && blueColor > 250) {
   color = 8;//blue
 }
 else {
   color = 0;//unknown
 }
}

void calibrate() {
 Serial.println("Calibrating...");
 Serial.println("White");//aim sensor at something white
 //set calibration vaues:

 digitalWrite(13, HIGH);
 delay(2000);
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redMin = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenMin = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueMin = pulseIn(sensorOut, LOW);
 delay(100);
 Serial.println("next...");//aim sensor at something black
 digitalWrite(13, LOW);
 delay(2000);
 Serial.println("Black");

 //set calibration values:
 digitalWrite(13, HIGH);
 delay(2000);
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redMax = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenMax = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueMax = pulseIn(sensorOut, LOW);
 delay(100);
 Serial.println("Done calibrating.");
 digitalWrite(13, LOW);
}

void printColor() {//print data
 Serial.print("R = ");
 Serial.print(redColor);
 Serial.print(" G = ");
 Serial.print(greenColor);
 Serial.print(" B = ");
 Serial.print(blueColor);
 Serial.print(" Color: ");
 switch (color) {
   case 1: Serial.println("WHITE"); break;
   case 2: Serial.println("BLACK"); break;
   case 3: Serial.println("ORANGE"); break;
   case 4: Serial.println("YELLOW"); break;
   case 5: Serial.println("PURPLE"); break;
   case 6: Serial.println("RED"); break;
   case 7: Serial.println("GREEN"); break;
   case 8: Serial.println("BLUE"); break;
   default: Serial.println("unknown"); break;
 }
}

void readColor() {//get data from sensor
 //red:
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redFrequency = pulseIn(sensorOut, LOW);
 redColor = map(redFrequency, redMin, redMax, 255, 0);
 delay(100);

 //green:
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenFrequency = pulseIn(sensorOut, LOW);
 greenColor = map(greenFrequency, greenMin, greenMax, 255, 0);
 delay(100);

 //blue:
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueFrequency = pulseIn(sensorOut, LOW);
 blueColor = map(blueFrequency, blueMin, blueMax, 255, 0);
 delay(100);
}
