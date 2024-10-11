// SPDX-FileCopyrightText: 2023 Carter Nelson for Adafruit Industries
//
// SPDX-License-Identifier: MIT
// --------------------------------------
// i2c_scanner
//
// Modified from https://playground.arduino.cc/Main/I2cScanner/
// --------------------------------------

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// // Set I2C bus to use: Wire, Wire1, etc.
// #define WIRE Wire

LiquidCrystal_I2C lcd(0x27, 16, 2);
int positionX = 0;

void setup() {
  
  // WIRE.begin();

  // Serial.begin(9600);
  // while (!Serial)
  //    delay(10);
  // Serial.println("\nI2C Scanner");


  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
}


void loop() {
  if (positionX == 15) {
    positionX = 0;
  } else {
    positionX += 1;
  }

  lcd.clear();
  lcd.setCursor(positionX, 0);
  lcd.print("Hello world");
  delay(500);
  // byte error, address;
  // int nDevices;

  // Serial.println("Scanning...");

  // nDevices = 0;
  // for(address = 1; address < 127; address++ )
  // {
  //   // The i2c_scanner uses the return value of
  //   // the Write.endTransmisstion to see if
  //   // a device did acknowledge to the address.
  //   WIRE.beginTransmission(address);
  //   error = WIRE.endTransmission();

  //   if (error == 0)
  //   {
  //     Serial.print("I2C device found at address 0x");
  //     if (address<16)
  //       Serial.print("0");
  //     Serial.print(address,HEX);
  //     Serial.println("  !");

  //     nDevices++;
  //   }
  //   else if (error==4)
  //   {`
  //     Serial.print("Unknown error at address 0x");
  //     if (address<16)
  //       Serial.print("0");
  //     Serial.println(address,HEX);
  //   }
  // }
  // if (nDevices == 0)
  //   Serial.println("No I2C devices found\n");
  // else
  //   Serial.println("done\n");

  // delay(5000);           // wait 5 seconds for next scan
}