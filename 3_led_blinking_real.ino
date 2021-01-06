void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

}

void loop() {
   for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
       for(int m=0;m<2;m++)
       {
      digitalWrite(2,i);
      digitalWrite(3,j);
      digitalWrite(4,m);
      delay(500);
    }
  }
}
}
