#define SENSOR_PIN 4
#define buzzer 22

int lastState = HIGH;
int currentState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SENSOR_PIN,INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == HIGH && currentState == LOW) {
    tone(buzzer, 100);
    Serial.println("ada suaranya brok");
  }
  else if (lastState == LOW && currentState == HIGH) {
    noTone(buzzer);
    Serial.println("Yahh suaranya ilang");
  }

  lastState = currentState;
  delay(200);
}
