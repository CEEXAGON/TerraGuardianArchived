#include <BlynkSimpleEsp8266.h>
BlynkTimer timer 
#define PUMP D0
#define LED D4
#define humiditySensor  D2  
#define ON = LOW
#define OFF = HIGH
int sensorValue = 0;  
int HumidityValue , HumidityValueBlynk ;
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt ();
  Serial.print("V1 slider value is: ");
  Serial.println(pinvalue);
  if (pinvalue == 1){
    digitalWrite(Pump,ON); }
    else{
      digitalWrite(Pump,OFF);  
    }
  }

  void myTimerEvent()
  {
    Blynk.virtualWrite(V2,HumidityValueBlynk);
  }

void setup() 
{  
   pinMode(LED, OUTPUT);  
   pinMode(Pump, OUTPUT);
   digitalWrite(Pump, OUTPUT);  
   pinMode(HumiditySensor,INPUT);
   Serial.begin(115200);
   Blynk.begin(auth, ssid ,pass);
   timer.setInterval(1000L, myTimerEvent);
}

void loop() 
{
  HumidityValue = digitalRead(HumiditySensor);
    Serial.print ("HumidityValueBlynk :");  
    Serial.println (HumidityValueBlynk);
    if(HumidityValueBlynk == 1)
    {
      HumidityValueBlynk=0;
      digitalWrite(Pump,ON);
      delay(5000);
      digitalWrite(Pump,OFF);               
    }
    else
    {
      HumidityValueBlynk=100;
    }
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    delay(100);
    Blynk.run();
    timer.run();
}
