/* Interfacing Motor Driver [L293d] and lcd 
 *  
 *  IN1 IN2 IN3 IN4  Direction
 *  1    0   1   0   Forward 
 *  0    1   0   1   Backward
 *  1    0   0   0   Right 
 *  0    0   1   0   Left
 *  0    0   0   0   Stop
 *  1    1   1   1   Stop
 *  0    1   0   0   Backward Right
 *  0    0   0   1   Backward Left
 *  
 */
#include "LiquidCrystal.h"

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);//rs,en,D4,D5,D6,D7

void setup()
{
    lcd.begin(16,2);
    lcd.print("WELCOME TO IOT");
    lcd.setCursor(0,1);
    lcd.print("BOOTCAMP MB");
    delay(1000);
    for(int i=4;i<=7;i++)
    {
        pinMode(i,OUTPUT);
        digitalWrite(i,LOW);
    }
    Serial.begin(9600);
    Serial.println("Welcome To Robot Navigation Panel");
    delay(500);
}
void loop()
{
  while(Serial.available()>0)
  {
    char ch =Serial.read();
    Serial.println("Data Received:" +String(ch));
    delay(20);
    lcd.clear();
    lcd.print("Data Received:");
    lcd.print(ch);
    lcd.setCursor(0,1);
    if(ch=='F')
    {
      lcd.print("Forward");
      Serial.println("Moving Forward");
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);    
    }
    else if(ch=='B')
    {
      lcd.print("Backward");
      Serial.println("Moving Backward");
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);    
    }
    else if(ch=='L')
    {
      lcd.print("Left");
      Serial.println("Moving Left");
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);    
    }
    else if(ch=='R')
    {
      lcd.print("Right");
      Serial.println("Moving RIGHT");
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);    
    }
    else if(ch=='S')
    {
      lcd.print("Stop");
      Serial.println("Stop");
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);    
    }
  }
}
