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
  pinMode(buttonPin[6], INPUT_PULLUP);
  Keyboard.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState[] = {digitalRead(buttonPin[0]),digitalRead(buttonPin[1]),digitalRead(buttonPin[2]),digitalRead(buttonPin[3]),digitalRead(buttonPin[4]),digitalRead(buttonPin[5]),digitalRead(buttonPin[6])};
    // If the button is pressed (goes from HIGH to LOW)
  for(int i = 0; i <7; i++){
    if (buttonState[i] == LOW && previousButtonState[i] == HIGH) {
      switch (i) {
    case 0: Keyboard.press(KEY_F14); break;
    case 1:  Keyboard.press(KEY_F15);  break;
    case 2:  Keyboard.press(KEY_F16);  break;
    case 3:  Keyboard.press(KEY_F17);  break;
    case 4:  Keyboard.press(KEY_F18);  break;
    case 5:  Keyboard.press(KEY_F19);  break;
    case 6:  Keyboard.press(KEY_F20);  break;
    default: 
      // Do nothing if the number is out of range
      return; 
      }    
      delay(50);                       
    }

  // If the button is released (goes from LOW to HIGH)
    if (buttonState[i] == HIGH && previousButtonState[i] == LOW) {
     Keyboard.releaseAll();
    delay(50);
    }

    previousButtonState[i] = buttonState[i]; 
  }
 

}