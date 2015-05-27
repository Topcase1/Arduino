#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address   

// info @ http://www.dx.com/p/lcd1602-adapter-board-w-iic-i2c-interface-black-works-with-official-arduino-boards-216865#.VWOGoFXtlHx

#define BACKLIGHT_PIN     13

void setup()
{
  // Switch on the backlight
 // pinMode ( BACKLIGHT_PIN, OUTPUT );
 // digitalWrite ( BACKLIGHT_PIN, LOW );
  
  lcd.begin(16,2);               // initialize the lcd 

  lcd.home ();                   // go home
  lcd.print("Ciao");  
  //lcd.setCursor ( 0, 1 );        // go to the next line
  //lcd.print (" WORLD!  ");      
}

void loop()
{

}