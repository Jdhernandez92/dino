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
    delay(500);
    activateSound(PIN);
    delay(500);
   }
  }
  
 void setupSound(int pin) {
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW);
 }
 
 void activateSound(int pin) {
  digitalWrite(LED, HIGH);
  digitalWrite(Eyes, HIGH);
  pinMode(pin, OUTPUT);
  delay(100);
  pinMode(pin, INPUT);
  delay(7000);
  digitalWrite(LED, LOW);
  digitalWrite(Eyes, LOW);
 }
