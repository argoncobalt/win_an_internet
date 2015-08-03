//From the article: http://bildr.org/2012/11/force-sensitive-resistor-arduino

int leftBoob = A0;
int rightBoob = A1;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int leftBoobSqueeze = analogRead(leftBoob); 
  int rightBoobSqueeze = analogRead(rightBoob); 
  
  if(leftBoobSqueeze > 0 || rightBoobSqueeze > 0) {
    if(leftBoobSqueeze >= rightBoobSqueeze) {
      Serial.print("left boob squeeze intensity: ");
      Serial.println(leftBoobSqueeze);
    }
    
    else if(leftBoobSqueeze <= rightBoobSqueeze) {
      Serial.print("right boob squeeze intensity: ");
      Serial.println(rightBoobSqueeze);
    }
}

  delay(250); //just here to slow down the output for easier reading
}

