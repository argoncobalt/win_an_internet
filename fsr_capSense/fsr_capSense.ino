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
  long pussyStroke =  cs_4_2.capacitiveSensor(30);

  // if both boobs and vagina are touched:
  if(pussyStroke > 30 && leftBoobSqueeze > 0 && rightBoobSqueeze > 0) {
    Serial.println("light up all LEDs and move all servos at once");
  }
  
  // if nothing is touched
  else if (pussyStroke <= 30 && leftBoobSqueeze == 0 && rightBoobSqueeze == 0) {
    Serial.println("NOTHING");
  }

  // else if 1-2 of them are touched:
  else {
    // logic for the boobs:
    if(leftBoobSqueeze > 0 || rightBoobSqueeze > 0) {
      // if only left boob is squeezed:
      if(leftBoobSqueeze > 0 && rightBoobSqueeze == 0) {
        Serial.print("left boob squeeze intensity: ");
        Serial.println(leftBoobSqueeze);
      }
      // if only right boob is squeezed:
      else if(rightBoobSqueeze > 0 && leftBoobSqueeze == 0) {
        Serial.print("right boob squeeze intensity: ");
        Serial.println(rightBoobSqueeze);
      }
      // if both boobs are squeezed:
      else if(rightBoobSqueeze > 0 && leftBoobSqueeze > 0) {
        Serial.println("right and left boobs squeezed");
      }
    }
    // logic for the vagina:
    if(pussyStroke > 30) {
      Serial.print("pussy stroke intensity: ");
      Serial.println(pussyStroke);
    }
  }

  delay(250); //just here to slow down the output for easier reading
}






