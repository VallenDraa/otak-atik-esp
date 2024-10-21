#define POTENSIO 35
#define BUZZER 12

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float potV = analogRead(POTENSIO);

  float volume = (potV / 4095) * 200;
  Serial.println(volume);

  tone(BUZZER, 100);
  analogWrite(BUZZER, volume);


  delay(10);
}
