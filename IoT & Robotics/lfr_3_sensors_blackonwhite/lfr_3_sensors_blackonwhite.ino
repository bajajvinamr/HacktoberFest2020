#define ls 2
#define ms 3
#define rs 4
#define lm1 5
#define lm2 9
#define rm1 6
#define rm2 10
#define vcc 7
#define vc 8
void setup() 
{
  // put your setup code here, to run once:
pinMode(ls,INPUT);
pinMode(ms,INPUT);
pinMode(rs,INPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(vcc,OUTPUT);
pinMode(vc,OUTPUT);
}

void loop() {
                  // put your main code here, to run repeatedly:
                  // ir sensor is high if no obstacle is ahead if something is ahead(or black colour doesn't reflect) it gives low
                   // BALCK PE HIGH WHITE PE LOW   
   int i1=digitalRead(ls);
   int i2=digitalRead(ms);
   int i3=digitalRead(rs);
   digitalWrite(vcc,HIGH);
   digitalWrite(vc,HIGH);
   
   if(i1==HIGH && i2==LOW && i3==HIGH)   // 0 && 1&& 0  move forward 
   {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
   }
   
   if(i1==LOW &&   i2==LOW && i3==HIGH)  //  && 1 move left
   {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
   
   }
   
   if(i1==HIGH && i2==LOW && i3==LOW) // 1 && 0 move right
   {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
   }
   
    if(i1==LOW && i2==LOW && i3==LOW)// 0 && 0 MOVE LEFT preferentially 
   {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
   }
    if(i1==HIGH && i2==HIGH && i3==HIGH) // 0 && 0 MOVE FORWARD
    {
       digitalWrite(lm1,HIGH);
       digitalWrite(lm2,LOW);
       digitalWrite(rm1,HIGH);
       digitalWrite(rm2,LOW);
    } 
  }
