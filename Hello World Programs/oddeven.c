#include<stdio.h>
#include<stdlib.h>
void even()
{
	int a,b;
	printf("\nEnter number till you want to find the even number. : ");
	scanf("%d",&a);
	printf("\nEVEN NO. :- \n");
	for(b=0;b<=a;b++)
	{
		if(b%2==0)
		{
			printf("%d\n",b);
		}
	}
	printf("\n%d",b);
}
void odd()
{
	int c,d;
	printf("\nEnter number till you want to find the odd number. : ");
	scanf("%d",&c);
	printf("\nODD NO. :-\n");
	for(d=0;d<=c;d++)
	{
		if(d%2==1)
		{
			printf("%d\n",d);
		}
	}
}
void yes()
{
	printf("1. EVEN\n2. ODD\n3. Exit");
}
void no()
{
	printf("\nGo ahead......");
}
int main()
{
	int ch,ch1;
	printf("1. EVEN\n2. ODD\n3. Exit");
	while(1!=0)
	{
		printf("\nEnter the no. : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:even();
					break;
			case 2:odd();
					break;
			case 3:exit(1);		
			default:printf("Wrong Number\n");				
		}
		printf("\nDo you want to print menu again ?");
		printf("\nEnter your choice (0/1) :");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 0:yes();
					break;
			case 1:no();
					break;
			default:printf("\nWrong Choice");		
		}
	}
}
