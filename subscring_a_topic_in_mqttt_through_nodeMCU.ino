/*programm: to subscribe a topic on mqtt server through nodeMCU*/
//initializing the required library files
#include<ESP8266WiFi.h>//esp8266 wifi library file
#include<PubSubClient.h>//mqtt publish/subscribe library file

// defined client id,topic, mqtt-server,ssid,and password
#define client_ID "rk"
#define subtopic "bala bhaskar"
const char* mqtt_server="test.mosquitto.org";
const char* ssid="Saikumar";
const char* pwd="0987654321";

//creation of class and object
WiFiClient espclient;//wifi class
PubSubClient client(espclient);//pusubclient class

void setup(){
  Serial.begin(9600);
  //wifi connection starts***
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
    Serial.print((char)payload[i]);//prints the data in subscribed topic at mqtt server on serialmonitor
  }
}

  void loop()
  {
    if(!client.connected()){
      reconnect();//calls the reconnect function
    }
    client.loop();//calls the callback function
    delay(3000);
    }
