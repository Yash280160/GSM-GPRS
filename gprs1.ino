 
#include <SoftwareSerial.h>
SoftwareSerial GPRS(10, 11);//Rx Tx
int pot1=A5;
int pot2=A4;
int a,b;
void setup() 
{
pinMode(pot1,INPUT);
pinMode(pot2,INPUT);
GPRS.begin(9600);
Serial.begin(9600);
Serial.println("start");


GPRS.println("AT+CSQ");

delay(100);
GPRS.println("AT+CGATT?");
delay(100);
GPRS.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
delay(2000);
GPRS.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
delay(4000);
GPRS.println("AT+SAPBR=1,1");
delay(4000);
GPRS.println("AT+HTTPINIT");
delay(3000);
}

void loop()
{
a=analogRead(pot1);
b=analogRead(pot2);
String s ="device.php?temp="+String(a)+"&gas="+String(b);
GPRS.print("AT+HTTPPARA=\"URL\",\"http://yash280160.000webhostapp.com/");
GPRS.print(s);
GPRS.print("\"\r\n");
delay(1000);
while(GPRS.available()!=0)
Serial.write((GPRS.read()));

GPRS.println("AT+HTTPACTION=0");
delay(5000);
while(GPRS.available()!=0)
Serial.write((GPRS.read()));

GPRS.println("AT+HTTPREAD");
delay(3000);
while(GPRS.available()!=0)
Serial.write((GPRS.read()));


}
