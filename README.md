# Hello_badge
Electronic name badge

Description : This project displays the information commonly found on a "Hello My Name is ..." paper badge on a LCD display attached to an Arduino board.

Sources
  -  Overview of 16x2 LCD panels available at : http://oomlout.com/parts/LCDD-01-guide.pdf

Target
  - Arduino Uno
  - pushbutton
  - 10K potentiometer
  - HD44780 compatible 2x16 LCD display
    - Pin 01 : Ground (LCD logic)
    - Pin 02 : +5V (LCD logic)
    - Pin 03 : Contrast (driven by potentiometer)
    - Pin 04 : RS (1st parameter in LiquidCrystal lcd(1,2,3,4,5,6))
    - Pin 05 : R/W (tie to Ground)
    - Pin 06 : Enable (2nd parameter in LiquidCrystal lcd(1,2,3,4,5,6))
    - Pin 7,8,9,10 - Do not use
    - Pin 11,12,13,14 : Data lines (3rd->6th parameter in LiquidCrystal lcd(1,2,3,4,5,6))
    - Pin 15 : +5V (LCD backlight)
    - Pin 16 : Ground (LCD backlight)

Revisions
  03/08/14
    - first version restoring functionality in the first prototype
  04/30/14
    - PDF overview of LCD added to project folder, URL in comments
  08/20/17
    - target information, revision history, feature requests, etc. moved to readme.md
    - fritzing file generated for non-i2c version of project
    
Feature Requests
  08/20/17 - Change name of project to eBadge
  08/20/17 - remove LED code
  08/20/17 - code cleanup
  08/20/17 - code version for i2c (#ifdef)?
