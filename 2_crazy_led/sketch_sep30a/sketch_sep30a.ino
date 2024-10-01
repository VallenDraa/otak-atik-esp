int lampu1 = 2;
int counterLampu1 = 0; 

int lampu2 = 4;

int delayTimeMs = 250;

void setup() {
  Serial.begin(9600);

  pinMode(lampu1, OUTPUT);
  pinMode(lampu2, OUTPUT);
}

void loop() {
  // Lampu 1 Hanya berkedip selama 10 Kali setiap 0.5 detik
  if (counterLampu1 < 10) {
    counterLampu1 += 1;
    digitalWrite(lampu1, HIGH);
    
    // tampilkan ke serial monitor lampu 1 telah berkedip berapa kali
    Serial.print("Lampu 1 telah berkedip sebanyak: ");
    Serial.print(counterLampu1);
    Serial.println();

    delay(delayTimeMs);
    digitalWrite(lampu1, LOW);
    delay(delayTimeMs);
  }
  

  // Dan Lampu 2 Menyala setelah Lampu 1 berkedip 10 Kali
  if (counterLampu1 >= 10) {
    digitalWrite(lampu2, HIGH);
    delay(delayTimeMs);
    digitalWrite(lampu2, LOW);
  }
}
