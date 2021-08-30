#include <LiquidCrystal.h>
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define E 8
#define RS 9

int sensorValue = 0;
int tempValue = 0;
int C = 0;
int buzzer = 3;
int light = 2;
int maxtemp =40;
int sensorThresh = 200;
const int ldrPin = A3;


LiquidCrystal LCD(RS, E, D4, D5, D6, D7);  

void setup() { 
	LCD.begin(16,2);
  	pinMode(A0,INPUT);
  	pinMode(A1,INPUT);
  	pinMode(light,OUTPUT);
  	pinMode(buzzer, OUTPUT);
  	pinMode(ldrPin, INPUT);
  	Serial.begin(9600);
}
 
void loop()
{
  	
  	sensorValue = analogRead(A0);
  	int ldrStatus = analogRead(ldrPin);
  
  	tempValue = analogRead(A1);
  	C = map(tempValue,0,1023,30,70);
  	if((C>41)||(sensorValue > sensorThresh))
    {
      	tone(buzzer, 1000, 1000);
      	digitalWrite(light, HIGH);
   		LCD.print("alert");
      	delay(100);
		      
    }
  	if(analogRead(A2)>0)
    {
      tone(buzzer, 1000, 1000);
      LCD.print("robbers");
      delay(10000);
      tone(buzzer, 1000, 1000);
    }
  
    else
    {
      noTone(buzzer);
      digitalWrite(light,LOW);
    }
  	
  	LCD.print("Temperature: ");
  	LCD.print(C);
  	delay(100);
  	LCD.clear();
  	LCD.print("Gas Value: ");
  	LCD.print(sensorValue);
  	delay(100);
  	LCD.clear();
  	if (ldrStatus <= 300) 
  	{
      	LCD.clear();
    } 
  	else 
  	{
      C=C+10;
      LCD.print("sunlight");
      delay(100);
    }
  	
  
    
}