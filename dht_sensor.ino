/*programm: to print the vlues of temperature and humidity in serial monitor usind dht type 11 sensor*/
//initilalize the dht sensor libraries
#include <DHT.h>
#include <DHT_U.h>
//define the pins in dht sensor
#define DHTPIN 3
#define DHTTYPE 11
//creation of dht class and object
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
dht.begin();//dht class begins
Serial.begin(9600);//serial monitor begins

}

void loop() {
 float temp,hum;//declare temperature as"temp humidity as "hum"
 temp=dht.readTemperature();//reads temperature value
 hum=dht.readHumidity();//reads humidity value
Serial.print("the temperature:");
Serial.print(temp);//prints temperature values
Serial.println("the humidity:");
Serial.print(hum);//prints the humidity values
}
