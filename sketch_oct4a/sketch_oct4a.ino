#define pirSensor 4
#define buzzer 22

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(pirSensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int status = digitalRead(pirSensor);

  Serial.print("status: ");
  Serial.println(status);

  if (status == 1) {
    tone(buzzer, 100);
    analogWrite(buzzer, 100);
    Serial.println("Ada orang cuy");
  } else {
    noTone(buzzer);
  }

  delay(150);

}
