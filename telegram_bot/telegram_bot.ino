#include <DHT.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "Harnas";
const char* password = "11111111";

const char* botToken = "7804678338:AAG_ykxcnWHPKBbpM24FHRBiLpBjNggaCSk";
const char* chatID = "5963143419";

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

const int DHT_PIN = 17;
const int DHT_TYPE = DHT22;
DHT dht(DHT_PIN, DHT_TYPE);

String currentMessage = "/off";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Mencoba menghubungkan ke WiFi...");
  }
  Serial.println("Terhubung ke WiFi!");

  client.setInsecure();  
  bot.sendMessage(chatID, "Bot Telegram sudah terhubung dengan ESP32!", "");
}

void loop() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  Serial.println("Message" + numNewMessages);

  for (int i = 0; i < numNewMessages; i++) {
    String newMessage = bot.messages[i].text;  
    String fromName = bot.messages[i].from_name;  

    Serial.println("Pesan diterima: " + newMessage);
    
    Serial.print(newMessage);
    Serial.print(newMessage == "/on");
    Serial.print(newMessage == "/off");

    if (newMessage == "/on" || newMessage == "/off") {
      currentMessage = newMessage;
    } else {
      bot.sendMessage(
        chatID, 
        "Perintah tidak dikenali. Gunakan /on untuk menyalakan atau /off untuk mematikan sensor DHT.", "");
    }
  }

  if (currentMessage == "/on") {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) { 
      Serial.println(F("Failed to read from DHT sensor!")); 
      return; 
    }

    String sensorMessage = "H: " + String(h) + "\nC: " + String(t);
    bot.sendMessage(chatID, sensorMessage ,"");
  }

  delay(1000);  
}