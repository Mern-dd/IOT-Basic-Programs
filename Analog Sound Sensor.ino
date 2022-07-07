
int buzzer = 7;
boolean val = 0;
int threshold = 540;

void setup(){
  pinMode(buzzer, OUTPUT);
  Serial.begin (9600);
}
 
void loop (){

  val = analogRead(A1);
  Serial.println (val);
  Serial.println("Data");
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val==HIGH) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }
}

