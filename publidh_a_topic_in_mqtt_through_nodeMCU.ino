/*programm: to publish a topic on mqtt server through nodeMCU*/
//initializing the required library files
#include<ESP8266WiFi.h>//esp8266 wifi library file
#include<PubSubClient.h>//mqtt publish/subscribe library file

// defined client id,topic, mqtt-server,ssid,and password
#define client_ID "rk"
#define PUB_TOPIC "bala bhaskar"
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
}

  void loop()
  {
    String msg;
    char mesg[20];
    msg="IOT WORLD";
    msg.toCharArray(mesg,20);//converting string data ib "msg" to characters and storing in "mesg"
    if(client.connect(client_ID))
  {
    Serial.print("sending message to mobile app");
    client.publish(PUB_TOPIC,mesg);//publishing the mesg in a declared topic
  }
  delay(2000);
    }
