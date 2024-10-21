#include <ESP32Servo.h>

#define SERVO_PIN 4
#define POTENSIO 35

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  servo.write(0);
}

void loop() {
  float potV = analogRead(POTENSIO);
  float angle = 
                // map(potV, 0, 4095, 0, 180);
                (potV / 4095) * 180;

  servo.write(angle);

  // for (int i = 0; i <= 180; i++) {
  //   servo.write(i);
  //   Serial.println(i);
  // }

  // for (int i = 180; i >= 0; i--) {
  //   servo.write(i);
  //   Serial.println(i);
  // }
  delay(200);
}
