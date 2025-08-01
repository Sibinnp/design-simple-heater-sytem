#include "DHT.h"

#define DHTPIN 5    
#define DHTTYPE DHT22   
#define HEATER_PIN 20
#define LEDR_PIN  28
#define LEDG_PIN 3
#define BUZZER_PIN 9

DHT dht(DHTPIN, DHTTYPE);

#define DHT22_PIN 5


float T0=25;
float T1=30;
float T2=40;
float T3=50;


void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(HEATER_PIN,OUTPUT);
  digitalWrite(HEATER_PIN,LOW);
  pinMode(LEDG_PIN,OUTPUT);
  pinMode(LEDR_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  
  
  

  dht.begin();
}

void loop() {
  
  delay(2000);
  float t;
  t =dht.readTemperature();

  
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print(("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  
  if (t<=T0)
  {
  Serial.print("idle,HEATER ON");
  digitalWrite (HEATER_PIN, HIGH);
  digitalWrite(LEDG_PIN, HIGH);

  }

  else if(t<T1)
  {
    Serial.print("STABILIZING,HEATER ON");
    digitalWrite(HEATER_PIN, HIGH);
    digitalWrite(LEDG_PIN,HIGH);
  }
  else if(t,T3)
  {
    Serial.print("HEATING,HEATER ON");
    digitalWrite(HEATER_PIN,HIGH);
  }
  else if(t>T2)
  {
  Serial.print("OVER HEATING,HEATER OFF");
  digitalWrite(HEATER_PIN,LOW);
  digitalWrite(LEDR_PIN,HIGH);
  digitalWrite(BUZZER_PIN,HIGH);
  
  }
  

}
