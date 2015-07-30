void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  Serial.println(touchRead(0));
  delay(200);
}
