/*
Modified version of code from http://www.instructables.com/id/Motion-Activated-LEDs/ 
and https://gist.github.com/stonehippo/308a5f5c49d4981ac976. Advice from forums as well
https://forums.adafruit.com/viewtopic.php?f=22&t=60675&sid=04d486fc2d72c141fe952dbbf38dc2a3
This is my first electronics project. I'm basically trying to get a PIR Sensor to trigger 
both an LED and a trigger pin on my Audio FX Sound board. I don't have any prior experience so
I'm trying to learn as I go.
If all goes well, I'm going to attach an LED to the eye on a cardboard cutout of a dinosaur.
The PIR Sensor will activate the glowing eye and play dinosaur effects through my audio fx board.
*/

int Eyes = 13; //LED for Dinosaur Eyes
int Buttons = 9; //soundboard buttons in parallel
int brightness = 255;
int fadeAmount = 1;
int pirState = LOW;
int pirVal = 0;
int pirPin = 12;
int PIN = 8; //trigger pin connected to Audio FX Soundboard
int minSecsBetweenRoars = 20;
long lastRoar = -minSecsBetweenRoars * 1000l;

void setup()  {
  Serial.begin(9600); 
  pinMode(Buttons, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(Eyes, OUTPUT);
  pinMode(PIN, INPUT);
  digitalWrite(PIN, LOW);
  delay(500);
  }

  
void loop() 
{
  pirVal = digitalRead(pirPin);
  long now = millis();
   if (brightness == 255)
  {
    delay(5000);
    brightness = brightness - fadeAmount;
    delay(30);
  }
  else if (brightness !=0 && brightness != 255)
  {
    analogWrite(Buttons, brightness);
    brightness = brightness - fadeAmount;
    delay(700);
  }
  if (pirVal == HIGH) 
  {
    if (now > (lastRoar + minSecsBetweenRoars * 1000l)) 
    {
      Serial.println("ROAR!");
      delay(500);
      digitalWrite(Eyes, HIGH);
      pinMode(PIN, OUTPUT);
      delay(300);
      pinMode(PIN, INPUT);
      lastRoar = now;
      analogWrite(Buttons, brightness);
      delay(5000); //trying to keep the Eyes of my dinosaur lit for a while after the sound plays.
      digitalWrite(Eyes, LOW);
      delay(500);
   }
   else 
   {
    Serial.println("Movement, No action.");
   }
  }
}
