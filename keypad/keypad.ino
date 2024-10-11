#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS =  4; 
const byte COLS =  4;

char keys[ROWS][COLS] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 14, 27}; 
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins,
colPins, ROWS, COLS);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  // lcd.print("Hello World");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key == 'C') {
      lcd.clear();
      // lcd.print("KETIK AKU BANG");
    } else {
      lcd.print(key);
    }
  }

}
