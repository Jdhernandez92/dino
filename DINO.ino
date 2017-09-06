/*
Modified version of code from http://www.instructables.com/id/Motion-Activated-LEDs/ 
and https://gist.github.com/stonehippo/308a5f5c49d4981ac976. Advice from forums as well
https://forums.adafruit.com/viewtopic.php?f=22&t=60675&sid=04d486fc2d72c141fe952dbbf38dc2a3

This is my first electronics project. I'm basically trying to get a PIR Sensor to trigger 
both an LED and a trigger pin on my Audio FX Sound board. I don't have any prior experience so
I'm trying to learn as I go.

If all goes well, I'm going to attach an LED to the eye on a cardboard cutout of a dinosaur.
The PIR Sensor will activate the glowing eye and play dinosaur effects through my audio fx board.

09/05/2017: The code has changed a lot since I started. I couldn't figure out how the "setupSound()" command worked
so I just wrote it all out in the loop. I added a minimum time between activation so it wouldn't be annoying.

everything seems to work out as planned.
*/

int Eyes = 4; //LED for Dinosaur Eyes
int pirState = LOW;
int pirVal = 0;
int pirPin = 12;
int PIN = 8; //trigger pin connected to Audio FX Soundboard
int minSecsBetweenRoars = 40;
long lastRoar = -minSecsBetweenRoars * 1000L;


void setup()  {
 
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Eyes, OUTPUT);
  pinMode(PIN, INPUT);
  /* I am powering the soundboard with the 5v from my arduino uno. Setting my arduino trigger pin
  to input sends it very little power and reduces chances of burning it out.
  switching the pinMode to output then back to input in the loop works just like going from high to low
  and will trigger the sound.
   */
  digitalWrite(PIN, LOW);
  delay(500);
  }
  
void loop() {
  pirVal = digitalRead(pirPin);
  if (pirVal == HIGH) { //if motion is triggered
   if(now> (lastRoar + minSecsBetweenRoars * 1000L)) { //if it's been 40 seconds since last trigger
    delay(500);
    digitalWrite(Eyes, HIGH); //turns on LED eyes
    pinMode(PIN, OUTPUT); //see above
    delay(300);
    pinMode(PIN, INPUT);
    lastRoar = now; //sets start point until it can be triggered again
    delay(7000); //keeps the LED eyes on for 7 seconds
    digitalWrite(Eyes, LOW); //turns off LED eyes
    delay(500);
   }
  }
 }
