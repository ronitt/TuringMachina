
int incomingByte = 0;    //for incoming serial data
char incomingChar;
char readword[] = "testing1";
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
     ireadit = false;
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.print(' ');  
    incomingChar = (char)incomingByte;
    Serial.print(incomingChar);
    if(incomingChar == readword[counter] )
    {
        counter++;
        if(incomingChar == '1')
            {
            ireadit = true;
            Serial.print('got the null');
             }
        else
            ireadit = false;
    }
    
    else
      counter = 0;
  }
  
}

