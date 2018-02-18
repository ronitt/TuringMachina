
#include <Servo.h>                       
    
Servo rotation;     
Servo shoulder;
Servo elbow;
Servo hand;
Servo flick;
Servo clench;

int rotationDeg;
int shoulderDeg;
int elbowDeg;
int handDeg;
int flickDeg;

int incomingByte = 0;
char incomingChar;

char raiseA[] = "rais1";
char lowA[] = "lowr1";
char wave[] = "wave1";
char clamp[] = "clmp1";

char commandList[][4] = {raiseA, lowA, wave, clamp};

int counter = 0;

char readCmd[4];

void moveRotation(int x){
  
   if(rotationDeg < 180){
    rotationDeg += x;
   }
   
   rotation.write(rotationDeg);
   Serial.println(rotationDeg);
   delay(3000);
   
}

void moveShoulder(int x){
  
   if(shoulderDeg < 180){
    shoulderDeg += x;
   }
   
   shoulder.write(shoulderDeg);
   Serial.println(shoulderDeg);
   delay(3000);
   
}

void moveElbow(int x){
  
   if(elbowDeg < 180){
    elbowDeg += x;
   }
   
   elbow.write(elbowDeg);
   Serial.println(elbowDeg);
   delay(3000);
   
}

void moveHand(int x){
  
   if(handDeg < 180){
     handDeg += x;
   }
   
   hand.write(handDeg);
   Serial.println(handDeg);
   delay(3000);
   
}

/*
boolean charArrComp(char toComp[]){
  int i = 0;
  while(toComp[i] != '1' && readCmd[i] != '1'){

    if(toComp[i] != readCmd[i]){
      return false;
      }

      i++;
      
    }

    return true;
  
  }
*/

void setup()                                
{ 
  Serial.begin(9600);
  rotation.attach(13);     
  shoulder.attach(12);
  elbow.attach(11);
  hand.attach(10);
  

 //Arm Set-up Commands to Stand-By

 rotation.write(0);
 delay(3000);
 shoulder.write(0);
 delay(3000);
 elbow.write(0);
 delay(3000);
 hand.write(0);
 delay(3000);
  

}  

 
void loop()                               
{   
  //counter = 0;
  /*
  while(Serial.available()){

      incomingByte = Serial.read();
      incomingChar = (char)incomingByte;
      
      readCmd[counter] = incomingChar;
      counter++;
      
  }*/


  moveShoulder(20);

  moveShoulder(-20);
  
  /*
  boolean found = false;

  while(found == false){

    if(charArrComp(commandList[0])){

      //raiseArmCommand();
      found = true;
      
    } else if(charArrComp(commandList[1])){

       //lowerArmCommand();
       found = true;
      
    } else if(charArrComp(commandList[2])){

       //waveCommand();
       found = true;
      
    } else if(charArrComp(commandList[3])){

       //clampCommand();
       found = true;
      
      }
 
    }*/
}





