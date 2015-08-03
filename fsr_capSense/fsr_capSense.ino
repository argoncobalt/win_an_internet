// capSense sketch combined with FSR sketch

#include <CapacitiveSensor.h>

int leftBoob = A0;
int rightBoob = A1;

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2);

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop(){
  int leftBoobSqueeze = analogRead(leftBoob); 
  int rightBoobSqueeze = analogRead(rightBoob); 

  long start = millis();
  long pussySqueeze =  cs_4_2.capacitiveSensor(30);

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

  if(pussySqueeze > 30) {
    Serial.print("pussy squeeze intensity: ");
    Serial.println(pussySqueeze);
  }

  if(pussySqueeze > 30 && leftBoobSqueeze > 0 && rightBoobSqueeze > 0) {
    Serial.print("light up all LEDs and move all servos at once");
  }

  delay(250); //just here to slow down the output for easier reading
}


