//bufepR5Bh3PMenhDQO9KckqKGWFDZsQ4Kignenj1mkS
//LINE NOTIFY
#include <TridentTD_LineNotify.h>
#include <WiFi.h>
#include<stdio.h>
#define SSID "Ace" // บรรทัดที่ 11 ให้ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD "6003579ace" // บรรทัดที่ 12 ใส่ รหัส Wifi
#define LINE_TOKEN "bufepR5Bh3PMenhDQO9KckqKGWFDZsQ4Kignenj1mkS" // บรรทัดที่ 13 ใส่ รหัส TOKEN ที่ได้มาจากข้างบน

#include "DHT.h"

#define DHTTYPE DHT11


//MOISTURE SENSOR
#define sensorPin A0  
#define RelayPin 2 
int sensorValue = 0;

//WATER LEVEL SENSOR
#define sensorPower 7
#define WaterSensorPin A1 
int waterSensor = 0;

void setup() {
  //MOISTURE SENSOR/PUMP
   Serial.begin(9600);  
   pinMode(sensorPin, INPUT);  
   pinMode(RelayPin, OUTPUT);
   digitalWrite(RelayPin, HIGH);  
  
  //WATER LEVEL SENSOR
    pinMode(sensorPower, OUTPUT);
   digitalWrite(sensorPower, HIGH);
   Serial.begin(9600);
  
  //LINE NOTIFY
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
  LINE.notify("TERRA_GUARDIAN");

void loop() {
 //WATER LEVEL SENSOR
 waterSensor = analogRead(WaterSensorPin);
  Serial.print("Water level: ");
  Serial.println(waterSensor);
  if(waterSensor < 7 ){
    Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);
  LINE.notify("น้ำเริ่มน้อยแล้ว ไปเติมด้วยน้าาา");
  }
  delay(1800000);
  
  //MOISTURE SENSOR/PUMP
  sensorValue = analogRead(sensorPin);  
  if( sensorValue < 350 ) {
    digitalWrite(RelayPin, LOW);  
  }
  else{
    digitalWrite(RelayPin, HIGH);  
  }  
  delay(500);          
  Serial.print("Moisture Level = " );                       
  Serial.println(sensorValue);             
}
