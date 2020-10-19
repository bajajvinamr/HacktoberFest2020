/*
BALANCING OF PARANTHESIS
Author:Debargha Mukherjee
GitHub:Debargha-arch
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

//Stack ADT created to store the brackets
struct stack
{
  char stk[max];
  int top;
};

struct stack s;

//Function to push element into a stack
void push(char item)
{
 if(s.top==(max-1))
 {
   printf("OVERFLOW\n");
 }
 else
 {
   s.top++;
   s.stk[s.top]=item;
 }
}

//Function to pop out element from a stack
void pop()
{
 if (s.top==-1)
 {
   printf("UNDERFLOW\n");
 }
 else
 {
   s.top--;
 }
}

//Function for checking the balanced condition for brackets.
void balance(char exp[max])
{
  int i=0;
  for(i=0;i<strlen(exp);i++)
  {
    if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
    {
    push(exp[i]);
    }
    if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
    {
     if(exp[i]==')')
     {
       if(s.stk[s.top]=='(')
       {
        pop();
       }
       else
       {
        printf("\nUNBALANCED EXPRESSION\n");
        break;
       }
     }
     if(exp[i]==']')
     {
       if(s.stk[s.top]=='[')
       {
        pop();
       }
       else
       {
        printf("\nUNBALANCED EXPRESSION\n");
        break;
       }
     }
     if(exp[i]=='}')
     {
       if(s.stk[s.top]=='{')
       {
        pop();
       }
       else
       {
        printf("\nUNBALANCED EXPRESSION\n");
        break;
       }
     }
    }
    if(s.top==-1)
    {
      printf("\nBALANCED EXPRESSION\n");
    }	
  }
}

int main()
{
 char exp[max];
 int i=0;
 s.top=-1;
 printf("\nEnter the expression : ");
 scanf("%s", exp);
 balance(exp);
}
