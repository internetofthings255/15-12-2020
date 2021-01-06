/*programm: using pir sensor making a room or locality as secure
when user gives command as"a" the rooom gets secure and alaram ons when unauthorised person enters the room
when user gives command as "b" the room gets unsecure. when unauthorised person enters alaram doesnt on*/
void setup()
{
  pinMode(2,INPUT);//declared pin2 as input
  Serial.begin(9600);//serial monitor begins
}
char alrm;
int flag;
void loop()
{
  int value=digitalRead(2);//reads the pir sensor values and stores in "value"
  alrm=Serial.read();//reads the data given in serialmonitor and stored in "alrm"
  if (Serial.available()>0)
  {
    if(alrm=='a')
    {
     flag=1;
    }
      if(alrm=='b')
      {
        
        flag=0;
      }
    
  }
  if(value==1&&flag==1)
  {

    Serial.println("Alarm on");//room gets secure
    delay(2000);
  }
  if(value==1&&flag==0)
  {

      Serial.println("Alaram off");//room gets unsecure
  }
  delay(1000);
}
