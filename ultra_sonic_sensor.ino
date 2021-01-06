/*programm: to claculate the unknown distance using ultrasonicsensor*/

void setup() {
  //configure the pins in arduino
pinMode(3,OUTPUT);
pinMode(4,INPUT);
Serial.begin(9600);//serial monitor begins
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(3,LOW);
delayMicroseconds(2);
digitalWrite(3,HIGH);
delayMicroseconds(10);
digitalWrite(3,LOW);
int duration,distance;//declaration of duration and distance
duration=pulseIn(4,HIGH);//calculation of duration
distance=(duration*0.034)/2;//calculation of distance
Serial.print("the Distance is:");
Serial.print(distance);//prints distance
Serial.println("cm");
delay(2000);

}
