// Declare the pins for the Button and the LED<br>

#define firstPin  2
#define numOfPins 2

int prevState[numOfPins];

int LED = 13;

void setup() {
  for (int i = 0; i < numOfPins; i++) {
    pinMode(i + firstPin, INPUT_PULLUP);
    prevState[i] = digitalRead(i + firstPin);
  }
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {};
}

void loop() {
  for (int i = 0; i < numOfPins; i++) {

    int buttonValue = digitalRead(firstPin + i);
    if (buttonValue == LOW) {
      digitalWrite(LED, HIGH);
      if (prevState[i] == HIGH)
        Serial.print(i + 1);
    } else {
      digitalWrite(LED, LOW);
    }
    prevState[i] = buttonValue;
  }
  delay(50);

}

