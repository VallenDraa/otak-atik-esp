#include <SPI.h>
#include <MFRC522.h>

#define SDA_PIN  21  // ESP32 pin GPIO5 
#define RST_PIN 22 // ESP32 pin GPIO27 

MFRC522 rfid(SDA_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {

      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();
      int size = rfid.uid.size;
      Serial.println(size);

      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }
}