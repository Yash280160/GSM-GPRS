int sw=3,b,c=2,a;
void setup()
{
 Serial.begin(9600);
 pinMode(sw,INPUT);
  pinMode(c,INPUT);
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
}

void loop() 
{
  Serial.print("start");
  a=digitalRead(sw);
  if(a==HIGH)
  {
    digitalWrite(13,LOW);
    Serial.print("ATD7247290602;");
    Serial.print("\r\n");
   
  }
else
{
  digitalWrite(13,HIGH);
}
delay(1000);
b=digitalRead(c);
if(b==HIGH)
{
  Serial.println("ATH");
  Serial.print("\r\n");
}
else
{}
}

