#include<stdio.h>
const int MAX=50;
int stack[50];
int choice,top=-1,x,i;
void push(void);
void pop(void);
void peek(void);
int isfull(void);
int isempty(void);
int main()
{
    printf("\nStack Operations:");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.PEEK\n\t 4.ISFULL\n\t 5.ISEMPTY\n\t 6.EXIT");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                if(isfull())
                  printf("\nStack is full.... ");
                else 
                  printf("\nStack is not full....");
                break;
            }
            case 5:
            {
                if(isempty())
                  printf("\nStack is Empty.... ");
                else 
                  printf("\nStack is not Empty....");
                break;
                break;
            }
            case 6:
            {
                printf("\nEXITING.... ");
                break;
            }
            default:
            {
                printf ("\nPlease Enter a Valid Choice.....");
            }
                
        }
    }
    while(choice!=6);
    return 0;
}
void push()
{
    if(top>=MAX-1)
    {
        printf("\nSTACK over flow...!!!");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<=-1)
    {
        printf("\nStack under flow...!!!");
    }
    else
    {
        printf("\nThe popped elements is %d",stack[top]);
        top--;
    }
}

void peek()
{
  printf("\nTop Element is %d",stack[top]);
}

int isfull()
{
  if(top>=MAX-1)
    return 1;
  else 
    return 0;
}

int isempty()
{
  if(top<0)
    return 1;
  else 
    return 0;
}

