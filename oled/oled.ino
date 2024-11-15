#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

int posX = 0;
int isIncPosX = true;

int posY = 0;
int isIncPosY = true;

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }
  delay(2000);
}

void loop() {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(posX, posY);

  if (posX == 0) {
    isIncPosX = true;
  } else if (posX == 105) {
    isIncPosX = false; 
  }

  if (posY == 0) {
    isIncPosY = true;
  } else if (posY == 56) {
    isIncPosY = false; 
  }

  posX = isIncPosX ? posX + 1 : posX - 1;
  posY = isIncPosY ? posY + 1 : posY - 1;
  
  oled.print("DVD");
  oled.display();
  
  delay(1);
}
