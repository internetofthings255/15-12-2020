/*programm: control the led on nodeMCU through mqtt server on mobile app
and to get acknowledgement oon mobile when led on or off in nodeMCU*/

#include<ESP8266WiFi.h>//included the esp8266 wifi library
#include<PubSubClient.h>//included the pubsub library in mqtt server
#define client_ID "ch.rajesh" // defined the client id
#define subtopic "world of AI"//defined the topic which has to be subscribed
//now declaration of ssid, password, and mqtt server in constant character poionters
const char* ssid="Rajesh";
const char* pwd="12345678";
const char* mqtt_server="test.mosquitto.org";
// now creating the class and object 
WiFiClient espclient;
PubSubClient client(espclient);
//connecting the nodemcu to wifi
void setup(){
  Serial.begin(9600);
  Serial.print("WiFi connecting with ssid of :");
  Serial.print(ssid);
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("....");
    delay(300);
  }
  Serial.print("wifi has been connected with IP of:");
  Serial.println(WiFi.localIP());
  //**** nodeMCU has successfully connected to wifi network*****
  client.setServer(mqtt_server,1883);//client is connected to server
  client.setCallback(callback);//declired to initiate call back function
  client.subscribe(subtopic);//client is subscribed to the topic
  pinMode(16,OUTPUT);//declaration of output pin of led on nodeMCU
}
//the reconnect function is initiated due to when he internet get interrupted then subscription gets lost then to reconnect 
//and subscription this function get help
void reconnect(){
  while(!client.connected()){
    Serial.print("attempting to connect client with client id");
    if(client.connected(client_ID)){
      Serial.println("client has connected to the client id");
      client.subscribe(subtopic);//client is subscribed to the topic
    }
  }
  
}
//this callback is usedto call the data in topic which is subscribed on server
void callback(char*topic,byte*payload,unsigned int length){
  Serial.print("data is obtained from topic :");
  Serial.println(topic);//print the name of topic
  for(int i=0;i<length;i++){
    Serial.print((char)payload[i]);
  }
  if((char)payload[0]=="1")
  {
    digitalWrite(16,1);//led on when payload gets 1
    client.publish("on");// acknowlwdgement of on prints on mobile app
  }
   if((char)payload[0]=="0")
   {
    digitalWrite(16,0);//led off when payload gets 0
    client.publish("off");// acknowlwdgement of off prints on mobile app
  }
}
void loop (){
  if(!client.connected()){
    reconnect();
  }
  client.loop();//loop is for cycling the call back function
  delay(3000);
}
