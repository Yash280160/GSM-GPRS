int sw = 3 ,a;
void setup() 
{
pinMode(13,OUTPUT);
pinMode(sw,INPUT);


}

void loop()
{
a= digitalRead(sw);
if(a==HIGH)
{
  Serial.print("ATD9752064664;");
  Serial.print("\r\n");
}
else
{
digitalWrite(led,HIGH);
}
delay(1000);
}

