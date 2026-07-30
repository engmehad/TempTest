#include <Arduino.h>

int buzzer=8;
int blueLed=4;
int redLed=5;
int temperaturePin=A0;
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int temperatureSensor=analogRead(temperaturePin);
  float temp=(temperatureSensor *0.03)+5;
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C ");
  delay(1000);
  if(temp>=33.5){
    digitalWrite(redLed,HIGH);
    digitalWrite(blueLed,LOW);
    tone(buzzer,900);
  }
    else{
    digitalWrite(redLed,LOW);
    digitalWrite(blueLed,HIGH);
    noTone(buzzer);
    }
  
}

