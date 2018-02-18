#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
char transmess[3]; //the string to print on the LCD

int incomingByte = 0;    //for incoming serial data
char incomingChar;
char readword[] = "testing1";
int tim = 500; //the value of delay time
int counter = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
}

void LCD(char message[])
{
    lcd.setCursor(15,0); // set the cursor to column 15, line 0
  for (int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
  {
    lcd.scrollDisplayLeft(); //Scrolls the contents of the display one space to the left.
    lcd.print(message[positionCounter1]); // Print a message to the LCD.
    delay(tim); //wait for 250 microseconds
  }
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left  corner.
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.print(' ');  
    incomingChar = (char)incomingByte;
    Serial.print(incomingChar);
    if(incomingChar == readword[counter] )
    {
        transmess[counter] = incomingChar;
        counter++;
        if(incomingChar == '1')
            {
            LCD(transmess);
            for ( int i =  0; i<counter-2; i++)
              transmess[i] = 0;
            counter = 0;
             }
    }
  }
    
    else
      counter = 0;

}
