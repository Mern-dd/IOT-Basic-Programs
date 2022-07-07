int buzzer = 7;

void setup() 
{
    // Defines the Buzzer pin as output 
    pinMode(buzzer,OUTPUT);    
}

void loop() 
{
    // Sounds the buzzer at the frequency relative to the note C in Hz
    tone(buzzer,261,100);    
    // Sounds the buzzer at the frequency relative to the note D in Hz   
    tone(buzzer,293,100);             

    // Sounds the buzzer at the frequency relative to the note E in Hz
    tone(buzzer,329,100);           


}
