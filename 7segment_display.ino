/*programm: to print 0-9 numbers in 7segment display based on input given in serial monitor */

int pin[7]= {2,3,4,5,6,7,8};//initialize the pin array of 7 elements
int seven [10][7]=  //initiallize seven array with 9 elements
{
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1},
  
};
void setup() {
for(int i=0;i<7;i++)//loop used to configure pinmodes using pin[7]array 
{
  pinMode(pin[i],OUTPUT);
}
Serial.begin(9600);//serial monitor begins
}

void loop() {
  if(Serial.available()>0)
  
  {
    int num=Serial.parseInt();//reads the given data in serialmonitor and stores in "num"
    for(int j=0;j<7;j++)
    {
      digitalWrite(pin[j],seven[num][j]);
    delay(300);
    }
    
  }
}
