
const int trigPin = 7;
const int echoPin = 6;
const int buzzer = 12;
const int LED= 10;
const int LED1 = 3;
const int LED2 = 4;

long time;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
   pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
   Serial.begin(9600); 
}

void loop() {
    // digitalWrite(buzzer, LOW);
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance = time * 0.034 / 2;

 if(distance == 2)
  {
    Serial.println(distance);
    Serial.print("cm \n");
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, LOW);
     digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
    delay(1000);
  }
  if(distance > 10 && distance <= 20)
  {
    Serial.println(distance);
    Serial.print("cm \n");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);
    delay(100);
  }

   
   if(distance > 21 && distance <= 30)
  {
    Serial.println(distance);
    Serial.print("cm \n");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);
    digitalWrite(LED1, HIGH);
     digitalWrite(LED2, LOW);
    delay(100);
  }

  if(distance > 31 && distance <= 40)
  {
    Serial.println(distance);
    Serial.print("cm \n");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);
  digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    delay(100);
  }
  
  
  else
  {
    Serial.println(distance);
    digitalWrite(buzzer, LOW);
    digitalWrite(LED , LOW);
  }
}
