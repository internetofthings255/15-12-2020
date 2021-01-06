/*programm: to print alphpabets in 7segment display based on alphabet given in serial monitor*/
//creation of arrays 
int pin[7]={2,3,4,5,6,7,8};
int seven [10][7]= {
  {1,1,1,0,1,1,1},
  {1,1,1,1,1,1,1},
  {1,0,0,1,1,1,0},
  {1,1,1,1,1,1,0},
  {1,0,0,1,1,1,1},
  {1,0,0,0,1,1,1},
  {1,0,1,0,0,1,1},
  {0,1,1,0,1,1,1},
  {0,1,1,1,0,0,0},
  {0,0,0,1,1,1,0},
  };
void setup() {
for(int i=0;i<7;i++)
{
  pinMode(pin[i],OUTPUT);//configure the pins in array as output
}
Serial.begin(9600);//serial monitor initilalize
}

void loop() {
  int value= Serial.parseInt();//reads the value in serialmonitor and stores in "value"
  if(value==seven[10][7])
  {
    for(int num=0;num<10;num++)
  
  {
    for(int j=0;j<7;j++)
    {
      digitalWrite(pin[j],seven[num][j]);
    delay(200);
    }
   
  }
}
}
