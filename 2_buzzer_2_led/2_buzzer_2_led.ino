int led1 = 2;
int buzzer1 = 4;

int led2 = 22;
int buzzer2 = 23;

int delayTime = 3500;
int buzzerToneHz = 100;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop()
{
  digitalWrite(led1, HIGH);
  tone(buzzer1, buzzerToneHz);
  delay(delayTime);

  noTone(buzzer1);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  tone(buzzer2, buzzerToneHz);
  delay(delayTime);

  noTone(buzzer2);
  digitalWrite(led2, LOW);
  digitalWrite(led1, HIGH);
  tone(buzzer1, buzzerToneHz);

  noTone(buzzer1);
}
