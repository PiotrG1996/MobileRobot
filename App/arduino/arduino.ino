#include <SoftwareSerial.h> 


#define clockPin 7    
#define latchPin  8    // Shift Register pins definition
#define dataPin  9     

#define PWM4  10
#define PWM2  5    // PWN pins definition
#define PWM1  6
#define PWM3  3

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT  = 4;
const int UPR= 5;
const int UPL = 6;    // Constants
const int DL = 7;
const int DR = 8;
const int OP = 10;
const int OL = 9;
const int STOP = 12;

int readString;
int speed_= 200;     
int serialData = 0;   
int speedData = 0;
const int MAX_CMD_LENGTH = 10;
char cmd[MAX_CMD_LENGTH];
int cmdIndex;


int calculate(int s){
  if(s<0){
    return 0;           // Prevention from overflow
  }
  if(s>255){
    return 255;
  }
}

void up()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B01010101 );  
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,calculate(speed_));
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,calculate(speed_));
}
void down() 
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B10101010 );  //3124      10 - L | 01 - P
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,calculate(speed_));
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,calculate(speed_));
}
void left()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B10010110 );    //-1432 
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,calculate(speed_));
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,calculate(speed_));
}
void right()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B01101001 );      
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,calculate(speed_));
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,calculate(speed_));
}
void rotate_left()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B10100101 ); 
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,calculate(speed_));
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,calculate(speed_));
}
void rotate_right()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B01011010 );    
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,calculate(speed_));
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,calculate(speed_));
}
void up_right()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B01010101 );   
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,0);
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,0);
}
void up_left()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B10101010 );   // set up bit  -10p
        digitalWrite(latchPin, HIGH);                        // change rotate direction
        analogWrite(PWM1,0);
        analogWrite(PWM2,calculate(speed_));              // set up individual motors speed
        analogWrite(PWM3,0);
        analogWrite(PWM4,calculate(speed_));
}
void down_right()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B10101010 );   
        digitalWrite(latchPin, HIGH);                        
        analogWrite(PWM1,0);
        analogWrite(PWM2,calculate(speed_));              
        analogWrite(PWM3,0);
        analogWrite(PWM4,calculate(speed_));
}
void down_left()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B10101010 );   
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,calculate(speed_));
        analogWrite(PWM2,0);
        analogWrite(PWM3,calculate(speed_));
        analogWrite(PWM4,0);
}
void stop_()
{
        digitalWrite(latchPin, LOW);         
        shiftOut(dataPin, clockPin, MSBFIRST, B01010101 );       
        digitalWrite(latchPin, HIGH);
        analogWrite(PWM1,0);
        analogWrite(PWM2,0);
        analogWrite(PWM3,0);
        analogWrite(PWM4,0);
}
void setup(){
  Serial.begin(9600); // speed of data transmition
  cmdIndex = 0;
  pinMode(3, OUTPUT); //PWM4
  pinMode(5, OUTPUT); //PWM2
  pinMode(6, OUTPUT); //PWM3
  pinMode(10, OUTPUT); //PWM1        
  pinMode(11, OUTPUT); //LED1
  pinMode(12, OUTPUT); //LED2
  pinMode(13, OUTPUT); //LED3
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH); // diode - high
  digitalWrite(13, HIGH);
  stop_();
}
  
void loop(){

while(Serial.available() > 0)  
{
 delay(3);
 char byteIn = Serial.read();
 cmd[cmdIndex] = byteIn;
 if(byteIn=='\n'){
        //command finished
        cmd[cmdIndex] = '\0';
        Serial.println(cmd);
        cmdIndex = 0;
        break;
 } else {
  if(cmdIndex++ >= MAX_CMD_LENGTH){
          cmdIndex = 0;
  }
 }
 serialData=1;
 speed_ = speedData;
}

if(serialData>0)
{  
  if(strcmp(cmd, "UP")  == 0){
    readString = 1;
    }
    if(strcmp(cmd, "DOWN")  == 0){
      readString = 2;
     }
      if(strcmp(cmd, "LEFT")  == 0){
        readString = 3;
       }
        if(strcmp(cmd, "RIGHT")  == 0){
          readString = 4;
         }
           if(strcmp(cmd, "UPRIGHT")  == 0){
            readString = 5;
            }
             if(strcmp(cmd, "UPLEFT")  == 0){
              readString = 6;
              }
               if(strcmp(cmd, "DOWNLEFT")  == 0){
                readString = 7;
                }
                 if(strcmp(cmd, "DOWNRIGHT")  == 0){
                  readString = 8;
                  }
                   if(strcmp(cmd, "RLEFT")  == 0){
                    readString = 9;
                    }
                      if(strcmp(cmd, "RRIGHT")  == 0){
                        readString = 10;
                      }
  if(strcmp(cmd, "STOP")  == 0){
    readString = 12;
  }
    if(strcmp(cmd, "SLOW")  == 0){
     readString = 13;
     }
        if(strcmp(cmd, "FAST")  == 0){
              readString = 13;
        }

switch(readString){
case 1: up();  break; 
case 2: down();  break; 
case 3: left();  break; 
case 4: right();  break; 
case 5: up_right();  break; 
case 6: up_left();  break; 
case 7: down_left();  break; 
case 8: down_right();  break; 
case 9: rotate_left();  break; 
case 10: rotate_right();  break;   
case 12: stop_();  break;   
case 13: speedData = 150;  break;   
case 14: speedData = 225;  break;   
default:
      break;
}
serialData=0;              // reset variables
readString=0;  

}
}
