/*
  Gunakan sensor DHT untuk membaca suhu dan kelembapan, dan
  tampilkan hasilnya ke LCD menggunakan button.
*/
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHT_PIN 14
#define DHT_TYPE DHT22

#define BUTTON_PIN 25

#define LCD_HORIZONTAL 16
#define LCD_VERTICAL 2

#define MAX_BUTTON_COUNTER 3

bool isPressed = false;
int buttonPressCounter = 0;

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, LCD_HORIZONTAL, LCD_VERTICAL);

void setup() {
  Serial.begin(112500);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);    
  dht.begin();

  lcd.print("Tekan Aku Bang!");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  delay(100);

  if (buttonState == HIGH) {
    isPressed = false;
  }

  if (buttonState == LOW && !isPressed) {
    lcd.clear();
    isPressed = true;
    buttonPressCounter = 
      buttonPressCounter == MAX_BUTTON_COUNTER 
        ? 1
        : buttonPressCounter + 1;

    Serial.println(buttonPressCounter);


    // Jika button ditekan sekali, LCD akan menampilkan kelembapan
    if (buttonPressCounter == 1) {
      float humidity = dht.readHumidity();

      lcd.print("1. H%: ");
      lcd.print(humidity);
    }
    // Jika button ditekan kedua kali, LCD akan menampilkan suhu dalam celcius
    else if (buttonPressCounter == 2) {
      float tempCelcius = dht.readTemperature();

      lcd.print("2. C: ");
      lcd.print(tempCelcius);
    } 
    // Jika Button ditekan ketiga kali, LCD akan menampilkan suhu dalam fahrenheit
    else if (buttonPressCounter == 3) {
      float tempFarenheit = dht.readTemperature(true);
      
      lcd.print("3. F: ");
      lcd.print(tempFarenheit);
    }
  }
}
