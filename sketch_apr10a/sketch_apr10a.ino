#include "Keyboard.h"

const int buttonPin[] =  {2,7,8,9,21,20,19};          // The pin your switch is connected to
int previousButtonState[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  pinMode(buttonPin[0], INPUT_PULLUP);
  pinMode(buttonPin[1], INPUT_PULLUP);
  pinMode(buttonPin[2], INPUT_PULLUP);
  pinMode(buttonPin[3], INPUT_PULLUP);
  pinMode(buttonPin[4], INPUT_PULLUP);
  pinMode(buttonPin[5], INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState[] = {digitalRead(buttonPin[0]),digitalRead(buttonPin[1]),digitalRead(buttonPin[2]),digitalRead(buttonPin[3]),digitalRead(buttonPin[4]),digitalRead(buttonPin[5])};
    // If the button is pressed (goes from HIGH to LOW)
  for(int i = 0; i <8; i++){
    if (buttonState[i] == LOW && previousButtonState[i] == HIGH) {
      Keyboard.press('F' + String(i+12));           
      delay(50);                      
    }

  // If the button is released (goes from LOW to HIGH)
    if (buttonState[i] == HIGH && previousButtonState[i] == LOW) {
    Keyboard.release('F' + String(i+12));
    delay(50);
    }

    previousButtonState[i] = buttonState[i]; 
  }
 

}