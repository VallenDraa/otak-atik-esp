#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

#define ROWS 4
#define COLS 4
#define MULTIPLICATION '*'
#define ADDITION 'A'
#define SUBTRACTION 'B'
#define DIVISION 'C'
#define RESULT 'D'
#define CLEAR '#'

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float num1 = 0;
float num2 = 0;
// kalo masih \0 berarti operator belum di tekan dan masih kumpulan angka pertama
char operatorKey = '\0'; 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();

  if (!key) {
    return;
  }

  if (key >= '0' && key <= '9') {
    if (operatorKey == '\0') {
      num1 = (num1 * 10) + (key - '0'); // konversi char ke int
      lcd.setCursor(0, 0);
      lcd.print(num1);
    } else {
      num2 = (num2 * 10) + (key - '0'); // konversi char ke int
      lcd.setCursor(0, 1);
      lcd.print(num2);
    }
  }

  if (key == ADDITION || key == SUBTRACTION || key == MULTIPLICATION || key == DIVISION) {
    operatorKey = key;

    if (key == ADDITION) {
      lcd.print("+");
    } else if (key == SUBTRACTION) {
      lcd.print("-");
    } else if (key == MULTIPLICATION) {
      lcd.print("*");
    } else if (key == DIVISION) {
      lcd.print("/");
    }
  }

  if (key == RESULT) {
    bool hasZeroDivisionError = false;
    float result = 0;

    if (operatorKey == ADDITION) {
      result = num1 + num2;
    } else if (operatorKey == SUBTRACTION) {
      result = num1 - num2;
    } else if (operatorKey == MULTIPLICATION) {
      result = num1 * num2;
    } else if (operatorKey == DIVISION) {
      if (num2 == 0) {
        hasZeroDivisionError = true;
      }

      result = num2 != 0 ? num1 / num2 : 0;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Result: ");
    lcd.setCursor(0, 1);

    if (hasZeroDivisionError) {
      lcd.print("Zero Div Error!");
    } else {
      lcd.print(result);
    }

    delay(3000);
    lcd.clear();
    resetNumsAndOperator();
  }

  if (key == CLEAR) {
    lcd.clear();
    resetNumsAndOperator();
  }
}

void resetNumsAndOperator() {
  num1 = 0;
  num2 = 0;
  operatorKey = '\0';
}
