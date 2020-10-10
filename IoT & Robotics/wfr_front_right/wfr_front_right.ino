#include <NewPing.h>

#define noofsonar 2
#define maxdist 400
#define trigpin1 2
#define echopin1 3
#define trigpin2 4
#define echopin2 5
#define lm1 6
#define lm2 7
#define rm1 8
#define rm2 9
#define vcc 10
//int rngfrot=0;
int rngwall=0;
NewPing sonar[noofsonar]={
  NewPing(trigpin1,echopin1,maxdist),
  NewPing(trigpin2,echopin2,maxdist)
};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);
pinMode(trigpin2,OUTPUT);
pinMode(echopin2,INPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(vcc,OUTPUT);
digitalWrite(trigpin1,LOW);
digitalWrite(trigpin2,LOW);  
}
int toCloseWall = 15;           //Initialze and define the values for distance between wall and robot

int toFarWall = 20;

int toCloseFront = 10,rangeFront,rangeWall;
void loop() {
  // put your main code here, to run repeatedly:
  
Main:

  rangeFront = readRangeFront();  // Read the sensor value by the function call

  Serial.print(rangeFront);          

  Serial.print(" Front");

  Serial.println();

  rangeWall = readRangeWall();

  Serial.print(rangeWall);

  Serial.print(" Wall");

  Serial.println(); 

 if (rangeFront < toCloseFront)  //Condition to check whether front sensor is close to robot

 {

    delay(500);

    drive_backward();

    delay(500);

    Serial.print(" Drive Back");

    //turn_right();

    Serial.print(" LEFT Turn");

    Serial.println();

    delay(800);

    drive_forward();

    turn_left();

    delay(1700);

    goto Main;   

  } 

 

  if(rangeWall > toCloseWall && rangeWall < toFarWall) //condition to check distance measured by front and side sensor is maintained correctly

  {

    drive_forward();

    Serial.print(" Drive Forward");

    Serial.println();

    goto Main;

  } 

 

  if (rangeWall < toCloseWall)                       //condition to check side wall is close to robot

  {

    delay(100);

    turn_left();

    //turn_right();

    delay(500);

    Serial.print(" Turn Left");

    drive_forward();

    Serial.print(" Drive Forward");

    Serial.println();

    goto Main;

  }

  if (rangeWall > toFarWall)                         //condition to check robot is far from side wall

  {

    delay(100);

    turn_right();

    //turn_left();

    Serial.print(" Turn Right");

    delay(500);

    drive_forward();

    Serial.print(" Drive Forward");

    Serial.println();

    goto Main;

  } 

}

 

void motor_stop()                                  // function to stop the robot

{   

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, LOW);

}

 

void drive_forward()                               // function to drive the robot forward

{   

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

}

 

void drive_backward()                             // function to drive the robot backward

{   

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, HIGH);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, HIGH);

}

 

void turn_left()                                  // function to turn the robot left

{  

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

}

 

void turn_right()                                     //function to turn the robot right

{

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, LOW);

}

 

int readRangeFront()                                 //function to read the front sensor value

{

  delay(50);

  unsigned rangeFront = sonar[0].ping_cm();

  //sonar[0].timer_stop();

  return rangeFront;

}

int readRangeWall()                                 // function to read the left sensor value

{

  delay(50);

  unsigned rangeWall = sonar[1].ping_cm();

  //sonar[1].timer_stop();

  return rangeWall;

}
