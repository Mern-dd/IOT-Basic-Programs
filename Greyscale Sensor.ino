
const int led=7; 
const int buzzer=10; 
const int sensor = A0; 

void setup () {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  int val=analogRead(sensor); 
  
  Serial.println(val);
  if (val>=4 && val<=50 ) { 
    digitalWrite(led, HIGH); 
   
  }
    else if(val>=251 && val<=400)
  {
    digitalWrite(led, LOW); 

    
    }
    else if(val>400)
  {
    digitalWrite(led, HIGH); 
     delay(800); 
    digitalWrite(led, LOW);
     delay(800); 
    digitalWrite(led, HIGH);
     delay(800); 
    digitalWrite(led, LOW);
    delay(800); 
    }
  else {
    digitalWrite(led, LOW); //LED gets OFF permanently until value is below 500
  }

 
}
