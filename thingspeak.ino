/*programm: to monitor the temperature and humidity in thingspeak server by creating a channel in it*/
//initializing required lilbraries
#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
//declaring pin connected dht sensor to nodemcu
#define DHTPIN 5
#define DHTTYPE DHT11
//assighning wifi-ssid,password. and channel number and api key
const char* ssid="Saikumar";
const char* pwd="987654321";
unsigned long channelno=1277948;
const char* APIkey ="1Y0Y3QRMMZA0WPT2";
//creation of class and object
WiFiClient client;
DHT dht(DHTPIN,DHTTYPE);

void setup(){
  Serial.begin(9600);
  //wifi connection gets start********
  Serial.print("wifi connection with :");
  Serial.print(ssid);
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("******");
    delay(200);
  }
  Serial.print("wifi has succesfull connected with:");
  Serial.print(WiFi.localIP());
  //****** wifi connection has completed
  ThingSpeak.begin(client);
  dht.begin();
  pinMode(5,INPUT);//declared gpio 5th pin to read dht sensor values
}

void loop(){
  int temp,hum;
  temp=dht.readTemperature();
  hum=dht.readHumidity();
  if(isnan(temp)||isnan(hum)){
    Serial.println("sensor failed to read the data");
  }
  ThingSpeak.setField(1,temp);//creating a field on temperature
  ThingSpeak.setField(2,hum);//creating a field on humidity
  int webstatus=ThingSpeak.writeFields(channelno, APIkey);
  if(webstatus==200){
    Serial.print("uploaded successfully");
  }
  else{
    Serial.print("uploaded unsuccessfully");
    Serial.print(webstatus);
  }
}
