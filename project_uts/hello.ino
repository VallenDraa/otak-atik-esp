#define button 4

#define lampu_1 22
#define lampu_2 23
#define lampu_3 16

int counterButton = 0;
int isPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
 
  pinMode(lampu_1, OUTPUT);
  pinMode(lampu_2, OUTPUT);
  pinMode(lampu_3, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(button);
  delay(10);

  if (buttonState == HIGH) {
    isPressed = false;
  }

  if (buttonState == LOW && !isPressed) {
    isPressed = true;
    counterButton += 1;
    Serial.println(counterButton);

    if (counterButton % 3 == 0) {
      digitalWrite(lampu_1, HIGH);
    } 

    else if (counterButton % 5 == 0) {
      digitalWrite(lampu_2, LOW);
    }

    else if (counterButton % 3 == 0 && counterButton % 5 == 0) {
      digitalWrite(lampu_3, HIGH);
    }
  }
}