#include <DHT.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHT_PIN 16
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);    
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) { 
    Serial.println(F("Failed to read from DHT sensor!")); 

    return; 
  }

  lcd.clear();
  lcd.print("H%: ");
  lcd.print(h);
  lcd.print(", ");

  lcd.print("C: ");
  lcd.setCursor(0, 1);    
  lcd.print(t);
  lcd.print(", ");

  lcd.print("F: ");
  lcd.print(f);

}
