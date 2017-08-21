/*
Project Name : Electronic Badge
Developer : Eric Klein Jr. (temp2@ericklein.com)
Description : Name badge that rotates pre-set hello messages based on button presses.
See README.md for target information, revision history, feature requests, etc.
*/

// include the LCD library code, which is a base Arduino library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// io pins used in the project
const int BUTTON = 7;
const int LED = 13;  //used for debug only; all references to LED can be removed if desired

// messages to display - use same str length to overwrite previous line on-screen
String name = "I'm Eric Klein";
char* description[] = {"Lemnos Labs     ", "Anne's Husband  ", "Angel Investor  ", "Nick's Dad      ","Cubmaster       "};
int descriptionMax = 4;
int descriptionCycle = 0;

int LEDstate = HIGH;

 // variable for reading the pushbutton status
int buttonState;
int lastButtonState = LOW;

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup()
{ 
  // initiatialize pins
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  // display initial screen information
  // Display your name on the top line of the display, which will remain static
  lcd.print(name);
    lcd.setCursor(0, 1);
  lcd.print(description[descriptionCycle]);
  
  // set initial output states
  digitalWrite(LED, LEDstate);
}

void loop()
{
  // set the cursor to column 0, line 1. line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);

  // read the state of the switch
  int reading = digitalRead(BUTTON);
  
   // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) 
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        LEDstate = !LEDstate;
        if (descriptionCycle < descriptionMax) 
        {
          descriptionCycle++;
        }
      else
      {
        descriptionCycle = 0;
      }
    }
   }
  }
  
    // set the LED:
  digitalWrite(LED, LEDstate);
  lcd.print(description[descriptionCycle]);
  
   // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}
