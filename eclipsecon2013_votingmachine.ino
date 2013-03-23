// This code turns a led on/off through a debounced switch

#include <Bounce.h>

// This code turns a led on/off through a debounced button
// Build the circuit indicated here: http://arduino.cc/en/Tutorial/Button

#define BUTTON_MINUS_1  2
#define BUTTON_ZERO   3
#define BUTTON_PLUS_1  4

// Instantiate Bounce objects with a 5 millisecond debounce time
Bounce bouncer_Minus_One =  Bounce(BUTTON_MINUS_1,5); 
Bounce bouncer_Zero =       Bounce(BUTTON_ZERO,5); 
Bounce bouncer_Plus_One =   Bounce(BUTTON_PLUS_1,5); 


void setup() {
  pinMode(BUTTON_MINUS_1,INPUT);
  pinMode(BUTTON_ZERO,INPUT);
  pinMode(BUTTON_PLUS_1,INPUT);
  
  Serial.begin(9600);
}

void loop() {
 byte buttonsStates = 0 ;
  
  // Update the debouncers
 bouncer_Minus_One.update();
 bouncer_Zero.update();
 bouncer_Plus_One.update();
 
 buttonsStates += (bouncer_Minus_One.risingEdge() ? 4 : 0);
 buttonsStates += (bouncer_Zero.risingEdge() ? 2 : 0);  
 buttonsStates += (bouncer_Plus_One.risingEdge() ? 1 : 0);  
 
 if (buttonsStates > 0) {
   Serial.print(buttonsStates);
// Serial.write(buttonsStates);
 }
}
