/*
 * serial_echo.pde
 * ----------------- 
 * Echoes what is sent back through the serial port.
 *
 * http://spacetinkerer.blogspot.com
 */

int incomingByte = 0;    //for incoming serial data
char incomingChar;
char readword[] = "testing";
bool ireadit = false;
int counter = 0;

void setup() {
    Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // send data only when you receive data:
    digitalWrite(LED_BUILTIN,LOW);
  if(ireadit)
     digitalWrite(LED_BUILTIN,HIGH);
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    incomingChar = (char)incomingByte;
    if(incomingChar == readword[counter] )
    {
        counter++;
        if(incomingChar == '\0')
            ireadit = true;
        else
            ireadit = false;
    }
    
    else
      counter = 0;
  }
  
}

