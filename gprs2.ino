#include <SoftwareSerial.h>
SoftwareSerial GPRS(10, 11);//rx,tx
int led1=A5;
int led2=A4;
int led3=A3;
int led4=A2;
int led5=A1;
char dataa[50],dataaa[30];

int i,j,k;
char y;

void setup()
{
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
GPRS.begin(9600);
Serial.begin(9600);
Serial.println("start");
net();
}
void loop()
{
GPRS.print("AT+HTTPPARA=\"URL\",\"http://yash280160.000webhostapp.com/value.php");
GPRS.print("\"\r\n");
delay(1000);
ShowSerialData();
GPRS.println("AT+HTTPACTION=0");
delay(5000);
GPRS.println("AT+HTTPREAD");
ShowSerialData();
j=0;
for(i=0;i<6000;i++)
{
if(GPRS.available())
{
y=GPRS.read();
dataa[j]=y;
j++;
}
delay(1);
}
Serial.println("Dataaaaa");
for(i=0;i<=j;i++)
{
//Serial.print(dataa[i]);
if(dataa[i]=='*')
break;
}
k=0;
for(i=i;i<=j;i++)
{
dataaa[k]=dataa[i];
k++;
//Serial.print(dataa[i]);
}
for(i=0;i<=k;i++)
{
Serial.print(dataaa[i]);
}
if(dataaa[1]=='1')
{
digitalWrite(led1,HIGH);
}
else
{
digitalWrite(led1,LOW);
}
if(dataaa[2]=='1')
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
if(dataaa[3]=='1')
{
digitalWrite(led3,HIGH);
}
else
{
digitalWrite(led3,LOW);
}
if(dataaa[4]=='1')
{
digitalWrite(led4,HIGH);
}
else
{
digitalWrite(led4,LOW);
}
if(dataaa[5]=='1')
{
digitalWrite(led5,HIGH);
}
else
{
digitalWrite(led5,LOW);
}
Serial.println();
//Serial.print(cnt1);
Serial.println();
//Serial.write(GPRS.read());
// while(Serial.available())
// GPRS.write(Serial.read());
}
void ShowSerialData()
{
while(GPRS.available()!=0)
Serial.write((GPRS.read()));
}
void net()
{
GPRS.println("AT+CSQ");
delay(100);
ShowSerialData();
GPRS.println("AT+CGATT?");
delay(100);
ShowSerialData();
GPRS.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
delay(2000);
ShowSerialData();
GPRS.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
delay(4000);
ShowSerialData();
GPRS.println("AT+SAPBR=1,1");
delay(4000);
GPRS.println("AT+HTTPINIT");
delay(3000);
}
