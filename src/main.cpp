#include <Arduino.h>
#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
  Joystick.begin();
}

const int pinToButtonMap = 2;

int lastButtonState[9] = {0,0,0,0,0,0,0,0,0};

void loop() {
  // Read pin values
  int currentButtonState = lastButtonState[0] + lastButtonState[1];
  if (currentButtonState != lastButtonState[10]) 
  {
    if (currentButtonState == 0) 
    {currentButtonState=1;}
    else
    {currentButtonState=0;}
    Joystick.setButton(10, currentButtonState);
    lastButtonState[10] = currentButtonState;
  }
 


  for (int index = 0; index < 9; index++)
  {
    currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Serial.print(currentButtonState);
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
  
}