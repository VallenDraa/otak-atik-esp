#define BLYNK_TEMPLATE_ID "TMPL6pxwH-cg_"
#define BLYNK_TEMPLATE_NAME "hello world"
#define BLYNK_AUTH_TOKEN "UJ4ZyNYG8k8AuHYphRnsqVkBvWOuGBWB"

#include <WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Harnas";
char pass[] = "11111111";

#define BUZZER_PIN 5
#define DHT_PIN 4
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(BUZZER_PIN, OUTPUT);
}

BLYNK_WRITE(V1) {
  int volume = param.asInt(); 


  tone(BUZZER_PIN, 100);
  analogWrite(BUZZER_PIN, volume);
}

void loop() {
  Blynk.run(); 


  Blynk.virtualWrite(V2, analogValue);

  delay(500);
}
