const int led=13; 
const int gassensor = A0; 

void setup () {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(gassensor, INPUT);
}

void loop() {
  int value=analogRead(gassensor); 
  
  Serial.println(value);
  if(value >= 500){    
    digitalWrite(led,HIGH);
    int plot = value;
    Serial.println(plot);
    delay(1000);
    
    
  }
  else if(value < 500){   
    digitalWrite(led,LOW);
    Serial.println(value);
    int plot = value;
    Serial.println(plot);
    delay(1000);
  }
}
  /*if (val<=10) { 
    digitalWrite(led, LOW);
    delay(1000); 
   
  }
    else if(val>10)
  {
    digitalWrite(led, HIGH); 
        delay(1000); 

    }
  else {
    digitalWrite(led, LOW);
        delay(1000); 
  }*/

 


/*
const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin


void setup()
{
  Serial.begin(9600); //Initialize serial port - 9600 bps
  pinMode(13,OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  int value = digitalRead(7);
  int Gas_value = analogRead(gasPin);
  if(value == HIGH){
    Serial.println("Gas CO is detected");
    Serial.println(Gas_value);
    digitalWrite(13, HIGH);  
  }
  else{
    Serial.println("Gas CO is not detected");
    Serial.println(Gas_value);
    digitalWrite(13, LOW);
  }
} */
