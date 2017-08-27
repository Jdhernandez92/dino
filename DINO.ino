/*
Modified version of code from http://www.instructables.com/id/Motion-Activated-LEDs/ 
and https://gist.github.com/stonehippo/308a5f5c49d4981ac976
*/

int Eyes = 4;
int pirState = LOW;
int pirVal = 0;
int pirPin = 12;
int PIN = 8;
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
    digitalWrite(Eyes, HIGH);
    delay(500);
    activateSound(PIN);
    delay(7000);
    digitalWrite(Eyes, LOW);
    delay(500);
   }
  }
  
 void setupSound(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
 }
 
 void activateSound(int pin) {
  digitalWrite(LED, HIGH);
  digitalWrite(pin, LOW);
  delay(100);
  digitalWrite(pin, HIGH);
  digitalWrite(LED, LOW);
 }
