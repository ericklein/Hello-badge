/*
Project Name : Electronic Badge
Developer : Eric Klein Jr. (temp2@ericklein.com)
Description : eBadge that rotates pre-set messages based on button press

See README.md for target information, revision history, feature requests, etc.
*/

// Library initialization
#include <LiquidCrystal.h>
#include "buttonhandler.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Assign hardware specific information
const int buttonPin = 7;

// globals related to buttons
enum { BTN_NOPRESS = 0, BTN_SHORTPRESS, BTN_LONGPRESS };

// messages to display - use same str length to overwrite previous line on-screen
String name = "I'm Eric Klein";
char* description[] = {"Lemnos Labs     ", "Anne's Husband  ", "Angel Investor  ", "Nick's Dad      ","Cubmaster       "};
int descriptionMax = 4;
int descriptionCycle = 0;

// Instantiate button objects
ButtonHandler buttonTextSwitch(buttonPin);

void setup()
{ 
  buttonTextSwitch.init();
  
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
switch (buttonTextSwitch.handle()) {
  case BTN_SHORTPRESS:
    if (descriptionCycle < descriptionMax) 
        {
          descriptionCycle++;
        }
      else
      {
        descriptionCycle = 0;
      }
        // set the LED:
  digitalWrite(LED, LEDstate);
  lcd.print(description[descriptionCycle]);
    Serial.println("button short press ->rotate text"); //debug text
    break;
  case BTN_LONGPRESS:
    Serial.println("button long press"); //debug text
    break;
  }
}
