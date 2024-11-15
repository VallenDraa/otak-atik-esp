int relay = 15;

void setup() {
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  delay(2000);
}

void loop() {
  digitalWrite(relay, HIGH);
  delay(2000);
  digitalWrite(relay, LOW);
  delay(2000);
}
