#include<ESP8266WiFi.h>
#include<PubSubClient.h>
#define client_ID "rk"
#define subtopic "bala bhaskar"
const char* mqtt_server="test.mosquitto.org";
const char* ssid="Saikumar";
const char* pwd="0987654321";
WiFiClient espclient;
PubSubClient client(espclient);
void setup(){
  Serial.begin(9600);
  Serial.print("WiFi connection with ssid : ");
  Serial.print(ssid);
  WiFi.begin(ssid,pwd);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.println("*****");
    delay(200);
  }
  Serial.print("WiFi connected with :");
  Serial.println(WiFi.localIP());
  //wifi connection completed
  
  client.setServer(mqtt_server,1883);//connecting client to the server
  client.subscribe(subtopic);//subscribing the topic
  client.setCallback(callback);//declared for callback function
  pinMode(16,OUTPUT);
}
// if lack of internet we can lost the subscription of topic so we are declaring the reconnect 

void reconnect(){
  while(!client.connected()){
    Serial.println("attempting to connect client with server");
    if(client.connect(client_ID)){
      Serial.print("client is connected");
      client.subscribe(subtopic);//client get subscribed when internet accessed
    }
  }
}
void callback(char* topic,byte*payload,unsigned int length){
  Serial.print("the message is arrived from :");
  Serial.println(topic);
  for(int i=0;i<length;i++){
    Serial.print((char)payload[i]);
  }
  if((char)payload[0]=='1')
  {
    digitalWrite(16,0);
  }
  if((char)payload[0]=='0')
  {
    digitalWrite(16,1);
  }
  
  }

  void loop()
  {
    if(!client.connected()){
      reconnect();
    }
    client.loop();
    delay(3000);
    }
