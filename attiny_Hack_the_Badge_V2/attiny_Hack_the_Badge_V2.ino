/*  Hack the hacksaar.de badge 
 *  https://git.hacksaar.de/mase/tks-badge
 *  special thanks to mase, giving me the hardware to gain experiences 
 *  mancas@lugsaar.de
*/

// pins of the switches
const int SW1 = 10;  // numbers of the pushbutton pins
const int SW2 =  9;  
const int SW3 =  8;  

int ledPins[] = {0, 1, 2, 3, 4, 5, 6, 7}; // numbers of the LED pins
int pinCount = 8;  
  
// variables for reading the pushbutton status
int buttonStateSW1 = 0;  
int buttonStateSW2 = 0;
int buttonStateSW3 = 0;

//initializing a integer for incrementing and decrementing LEDs
volatile int i=150; // start value for LED dim 


void setup() {
  
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT); // LED output pins
    digitalWrite(ledPins[thisPin], HIGH); //initialising all output pins
    }
    
    for (int thisPin = 1; thisPin < pinCount; thisPin++) {
    analogWrite(ledPins[thisPin], i); // initial dim value for the pins  1 to 7 (pin 0 has the push function)
    }
  
  pinMode(SW1, INPUT); // the buttons 
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  
 
  digitalWrite(SW1, HIGH); // need to initialise
  digitalWrite(SW2, HIGH); 
  digitalWrite(SW3, HIGH); 
}

void loop() {
  
  pushButton();
  dimLED();
}


void dimLED(){
   
  for (int thisPin = 1; thisPin < pinCount; thisPin++) {
   analogWrite(ledPins[thisPin], i);// analogWrite dim values from 0 to 255
   }

  if (digitalRead(SW1)==HIGH) {
    if (i<255) {
      i=++i;//if pin SW1 is pressed, increase light
      delay(5);
      }
   }
     
  if (digitalRead(SW2)==HIGH) {
    if (i>0) {
      i=--i;// if pin SW2 is pressed, decrease light
      delay(5);
      }
   }
}


void pushButton() {
  
  // read state of switch 3
  buttonStateSW3 = digitalRead(SW3);

  // check if the button is pressed
  if (buttonStateSW3 == HIGH) {
    digitalWrite(ledPins[0], HIGH); // turn LED on
    } 
  
  else {
    digitalWrite(ledPins[0], LOW); // turn LED off
    }
}
