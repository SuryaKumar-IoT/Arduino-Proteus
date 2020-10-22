void setup()
{
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  pinMode(8,INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(8)==0)
  {
    digitalWrite(2,LOW);
  }
  else
  {
    digitalWrite(2,HIGH);
  }
}
