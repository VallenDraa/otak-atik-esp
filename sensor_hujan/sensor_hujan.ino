#define pin_DO 4
#define pin_AO 23

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_DO, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusDigital = digitalRead(pin_DO);
  int statusAnalog = analogRead(pin_AO);

  Serial.print("Outputnya Digital: ");
  Serial.println(statusDigital);

  Serial.print("Outputnya Analog: ");
  Serial.println(statusAnalog);

  delay(500);
}
