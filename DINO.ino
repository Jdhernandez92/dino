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

int Eyes = 4; //LED for Dinosaur Eyes
int pirState = LOW;
int pirVal = 0;
int pirPin = 12;
int PIN = 8; //trigger pin connected to Audio FX Soundboard
int LED = 13; 


void setup()  {
 
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Eyes, OUTPUT);
  setupSound(PIN);
  delay(500);
  }
  
void loop() {
  pirVal = digitalRead(pirPin);
  if (pirVal == HIGH) {
    delay(500);
    activateSound(PIN);
    delay(500);
   }
  }
  
 void setupSound(int pin) {
  pinMode(pin, INPUT); //changed based on advice from adafruit CS on forums (link above)
  digitalWrite(pin, LOW);
 }
 
 void activateSound(int pin) {
  digitalWrite(LED, HIGH);
  digitalWrite(Eyes, HIGH);
  pinMode(pin, OUTPUT);
  delay(100);
  pinMode(pin, INPUT);
  digitalWrite(LED, LOW);
  delay(7000); //trying to keep the Eyes of my dinosaur lit for a while after the sound plays.
  digitalWrite(Eyes, LOW);
 }
