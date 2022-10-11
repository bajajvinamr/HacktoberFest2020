#include <stdio.h>
int n, stack[10];
int top =-1, k;
void push()
{
	if(top==n-1)
	printf("Overflow");
	else
	{
	printf("Enter element to be pushed: ");
	scanf("%d",&k);
	top++;
	stack[top]=k;
	}
}

void pop()
{
	if(top==-1)
	printf("Stack underflow");
	else
	{
	k=stack[top];
	printf("Popped elemnt is %d",k);
	top--;
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else if (top==n)
	{
		printf("Stack overflow");
	}
	else
	{
		for(int i=0; i<=top; i++)
		printf("%d\t",stack[i]);
	}
}

int main()
{
	int c;
	printf("Enter stack size: ");
	scanf("%d",&n);

	printf("\n1) Push\n2) Pop\n3) Display\n4) Exit");
	while(c!=4)
	{
		printf("\n\nEnter your choice\n");
		scanf("%d",&c);	
		
		switch(c)	
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
				display();
				break;
			}
			
			case 4:
			{
				break;
			}
			
			default:
				printf("\nEnter a valid option 1/2/3/4");
			
	}
}
return 0;
}
