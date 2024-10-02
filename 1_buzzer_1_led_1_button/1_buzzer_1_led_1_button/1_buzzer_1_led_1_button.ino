#define button 4
#define lampu 22
#define buzzer 23

int counterButton = 0;
int isPressed = false;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(lampu, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (counterButton > 4) {
    return;
  }

  int buttonState = digitalRead(button);
  delay(10);

  if (buttonState == HIGH) {
    isPressed = false;
  }

  if (buttonState == LOW && !isPressed) {
    isPressed = true;
    counterButton += 1;

    // jika button ditekan sekali led akan menyala dan buzzer mati, 
    if (counterButton == 1) {
      digitalWrite(lampu, HIGH);
      noTone(buzzer);
    } 

    // jika button ditekan untuk kedua kali nya buzzer akan menyala   dan led akan mati,
    else if (counterButton == 2) {
      turnOnBuzzer();
      digitalWrite(lampu, LOW);
    }

    // jika button ditekan ketiga kalinya buzzer dan led akan menyala
    else if (counterButton == 3) {
      turnOnBuzzer();
      digitalWrite(lampu, HIGH);
    }

    // jika ditekan lagi semua komponen akan mati.
    else {
      digitalWrite(lampu, LOW);
      noTone(buzzer);
    }
  }
}

void turnOnBuzzer() {
  tone(buzzer, 100);
  // setting volume rendah, biar ga brisik
  analogWrite(buzzer, 20);
}