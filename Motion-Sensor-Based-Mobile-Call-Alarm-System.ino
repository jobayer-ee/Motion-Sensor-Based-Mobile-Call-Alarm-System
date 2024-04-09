/*
Abdullah Al Jobayer
Electrical Electronic Engineer
This code is available on Guithub
link- https://github.com/jobayer-ee/Motion-Sensor-Based-Mobile-Call-Alarm-System
*/


#include <SoftwareSerial.h>
const String PHONE = "+8801########";
#define rxPin 13
#define txPin 15
 
SoftwareSerial sim800(rxPin, txPin);
int pir_sensor = 12;
int LED = 14;
 
void setup() {
  pinMode(pir_sensor, INPUT);
  Serial.begin(115200);
  sim800.begin(9600);
  Serial.println("Multiple Motion Sensor Based Mobile Call Alarm System");
  delay(1000);
}
 
void loop() {
  while (sim800.available()) {
    Serial.println(sim800.readString());
  }
  while (Serial.available()) {
    sim800.println(Serial.readString());
  }
  int val = digitalRead(pir_sensor);
  if (val == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(LED, HIGH);
    Serial.println("calling....");
    delay(1000);
    sim800.println("ATD" + PHONE + ";");
    delay(20000);
  }
}