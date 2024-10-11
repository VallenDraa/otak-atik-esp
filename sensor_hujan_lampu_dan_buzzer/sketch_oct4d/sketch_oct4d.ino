#define sensorHujan 4
#define buzzer 23
#define lampu 12

bool isLightAlreadyOn = false;


void setup() {
  Serial.begin(9600);

  pinMode(sensorHujan, INPUT);
  pinMode(lampu, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int currentState = digitalRead(sensorHujan);

  if (currentState == LOW) {
    Serial.print(isLightAlreadyOn);

    if (isLightAlreadyOn == true) {
      digitalWrite(lampu, LOW);
      
      tone(buzzer, 200);

      isLightAlreadyOn = false;
    } else {
      noTone(buzzer);
      
      digitalWrite(lampu, HIGH);
      
      isLightAlreadyOn = true;
    }
  } else {
    noTone(buzzer);
    digitalWrite(lampu, LOW);
  }

  delay(500);
}
