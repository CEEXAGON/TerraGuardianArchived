//MOISTURE/PUMP
#define sensorPin A0  
#define pump 2 
int sensorValue = 0; 

//RESEVOIR LEVEL
#define sensorPower 7
#define WaterSensorPin A1 
int waterSensor = 0;


void setup() 
{
  //MOISTURE/PUMP
   Serial.begin(9600);  
   pinMode(sensorPin, INPUT);  
   pinMode(pump, OUTPUT);
   digitalWrite(pump, HIGH);  

   //RESEVOIR LEVEL
   pinMode(sensorPower, OUTPUT);
   digitalWrite(sensorPower, HIGH);
   Serial.begin(9600);
}

void loop() 
{
  //MOISTURE/PUMP
  sensorValue = analogRead(sensorPin);  
  if( sensorValue > 600 ) {
    digitalWrite(pump, LOW);  
  }
  else{
    digitalWrite(pump, HIGH);  
  }  
  delay(500);          
  Serial.print("Moisture Level = " );                       
  Serial.println(sensorValue); 
  
  //RESEVOIR LEVEL
  waterSensor = analogRead(WaterSensorPin);
  Serial.print("Water level: ");
  Serial.println(waterSensor);
  delay(1000);
  if(waterSensor < 1){
    digitalWrite(8,HIGH);
  }

  //BLUFF
  digitalWrite(9,HIGH);
  delay(500);
  digitalWrite(9,LOW);
}
