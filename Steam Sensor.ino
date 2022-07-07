

//const int buzzer=7;
const int W_LED=7;
const int B_LED=9;
int sensorValue;


void setup() 
{
  Serial.begin(9600);
 // pinMode(buzzer, OUTPUT);
  pinMode(W_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
}

     
void loop() 
{
  //digitalWrite(buzzer,HIGH);
  sensorValue = analogRead(0);   
  if(sensorValue >300){
    Serial.println("Steam is detected");
    Serial.println(sensorValue);
    digitalWrite(W_LED,HIGH);
    digitalWrite(B_LED,HIGH);
    delay(1000);
  }
  else{
    Serial.println("Steam is not detected");
    Serial.println(sensorValue);
    digitalWrite(W_LED,HIGH);
    digitalWrite(B_LED,LOW);
    delay(1000);
  }
  
}

