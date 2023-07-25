const int inputPin = 2;
const int led = 1;// The input pin you are using

void setup() {
  pinMode(led, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP); // Set the input pin as INPUT
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
}

void loop() {
  if (isInputHighForDuration(inputPin, 1000)) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
}

bool isInputHighForDuration(int pin, unsigned long duration) {
  unsigned long startTime = millis();
 
  while (digitalRead(pin) == HIGH) {
    if (millis() - startTime >= duration) {
      return true;
    }
  }
 
  return false;
}
