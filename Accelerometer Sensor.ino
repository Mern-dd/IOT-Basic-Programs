float X=0.774;  //replace your value
float gx=0.237; //replace your value

float Y=0.781; //replace your value
float gy=0.21; //replace your value

float Z=0.923; //replace your value
float gz=0.235; //replace your value

const int buzzer = 11;
const int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT); // Sets the buzzer as an output
  Serial.begin(9600);
}
void loop()
{
  
      int x,y,z;
      x=analogRead(5);
      y=analogRead(4);
      z=analogRead(3);
      x = (x*5/1024.0 - X)/gx,2;
      y = ((y*5/1024.0- Y)/gy),2;
      z = ((z*5/1024.0-Z)/gz),2;
      Serial.print("x= ");
      Serial.print(x);
      Serial.print(',');
      Serial.print("y= ");
      Serial.print(y);
      Serial.print(',');
      Serial.print("z= ");
      Serial.println(z);
      delay(300);
     
      if( x < 5)
      {
        Serial.println(" X axis ");
        Serial.println(" LED ");
        digitalWrite(ledPin, HIGH);
          delay(1000);
       
      }
      if( y < 5)
      {
        Serial.println(" Y axis ");
        Serial.println(" buzzer ");
        digitalWrite(buzzer, HIGH);
          delay(1000);
       
      }
      if( z < 5)
      {
        Serial.println(" Z axis ");
        Serial.println(" LED - buzzer ");
       
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzer, LOW);
          delay(1000);
      }
      delay(1000);
}


