/*programm: to print 0to9 numbers in 7segment display in repeated cycle with a short delay*/
//create some arrays
int pin[7]={2,3,4,5,6,7,8};
int seven [10][7]= {
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
for(int i=0;i<7;i++)
{
  pinMode(pin[i],OUTPUT);//configures the pins in array as output
}
}

void loop() {
  for(int num=0;num<10;num++)
  {
    for(int j=0;j<7;j++)
    {
      digitalWrite(pin[j],seven[num][j]);
    delay(100);
    }
    
  }
}
