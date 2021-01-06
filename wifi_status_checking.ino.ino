/*programm: to connect nodeMCU board to local WIFI and to monitor its status*/

#include <ESP8266WiFi.h>//initialize the esp8266 wifi library file
// declaration of ssid and password
const char* ssid="RK";
const char* pwd="12345678";
void setup(){
  Serial.begin(9600);
  //wifi connection starts***
  Serial.print("wifi connecting with ssid :");
  Serial.println(ssid);
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("************");
    delay(200);
  }
  Serial.print("wifi is sucessfully connected with ip address :");
  Serial.println(WiFi.localIP());//prints the connected local ip address
  //wifi connection completed
}

void loop()
{


}
