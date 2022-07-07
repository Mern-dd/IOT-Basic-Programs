const int buzzer = 8;
const int LED= 7;
void setup()
{
 pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop()
{
  int val;
      val=analogRead(0);  
      delay(100);
      Serial.print("Distance: ");
      Serial.println(val);
      digitalWrite(buzzer, LOW);
      digitalWrite(LED, LOW);


   if(val >=0 && val<=10)
  {
   Serial.print("Distance: ");
   Serial.println(val);
   digitalWrite(buzzer, HIGH);
   digitalWrite(LED, HIGH);

    
  }
  if(val >= 11 && val <= 50)
  {
    Serial.print("Distance: ");
    Serial.println(val);
    Serial.println(" cm");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);

    delay(100);
  }


   if(val > 51 && val <= 100)
  {
    
    
    Serial.print("Distance: ");
    Serial.println(val);
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, HIGH);

    delay(100);
  }

  if(val > 101 && val <= 150)
  {
     Serial.print("Distance: ");
   Serial.println(val);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, LOW);
     tone(buzzer,261);
    delay(100);
  }


  else
  {
    Serial.print("Distance: ");
    Serial.println(val);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED,HIGH);

  } 
}

