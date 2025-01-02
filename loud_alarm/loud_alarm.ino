#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// WiFi credentials
const char* ssid = "...";
const char* password = "...";

// Define pins for buzzer and LED
#define BUZZER_PIN 23

// Set up NTP Client
WiFiUDP ntpUDP;
NTPClient timeClient(
  ntpUDP, 
  "pool.ntp.org", 
  7 * 3600, // WIB
  2000
);

// Alarm time (24-hour format)
const int alarmHour = 3;  // Set your desired hour (7 AM)
const int alarmMinute = 0; // Set your desired minute (30)

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");

  timeClient.begin();
}

void loop() {
  timeClient.update();

  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();

  Serial.printf("Current Time: %02d:%02d\n", currentHour, currentMinute);

  if (currentHour == alarmHour && currentMinute == alarmMinute) {
    // No deactivate, the only way to deactivate is to reset the ESP32!
    Serial.println("ALARM TRIGGERED!");
    digitalWrite(BUZZER_PIN, HIGH);
  }

  delay(1000); // Check every second
}
