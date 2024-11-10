#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int cooler=6;
int heater=7;

void setup() {
 Serial.begin(9600);
 Serial.println("DHT11 TEST !");
 dht.begin();
 pinMode(cooler,OUTPUT);
 pinMode(heater,OUTPUT);
 
 

}

void loop() {
  float humid=dht.readHumidity();
  float temp=dht.readTemperature();
  Serial.print("Humidity:");
  Serial.print(humid);
  Serial.println("%");
  delay(500);
  Serial.print("Temperature:");
  Serial.print(temp);
  Serial.println("*C");
  delay(500);
  if(temp>28){
    digitalWrite(cooler,HIGH);
    digitalWrite(heater,LOW);
    
  }
   if(temp<20){
    digitalWrite(heater,HIGH);
    digitalWrite(cooler,LOW);
    
  }
