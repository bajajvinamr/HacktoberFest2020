#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;
struct node *last = NULL;

void create();
void display_forward();
void display_backward();

void insert_begin();
void insert_last(); 
void insert_specific();
void length();
void delete_first();
void delete_last();
void delete_specific();



void main()
{
    int ch;
    char choice;
    while (1)
    {
        //printf("Enter your option\n");
        printf("\n1. Create\n");
        printf("2. Insert at Begin\n");
        printf("3. Insert at Last\n");
        printf("4. Insert at Location\n");
        printf("5. Delete at First\n");
        printf("6. Delete at Last\n");
        printf("7. Delete specific\n");
        printf("8. Display Forward\n");
        printf("9.Display Backward\n");
        printf("10. Length of the list\n");
        printf("11. Exit\n");

        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_last();
            break;
        case 4:
            insert_specific();
            break;
        case 5:
            delete_first();
            break;
        case 6:
            delete_last();
            break;
        case 7:
            delete_specific();
            break;
        case 8:
            display_forward();
            break;
        case 9:
            display_backward();
            break;
        case 10:
            length();
            break;
        case 11:
            exit(1);
            break;
        default:
            printf("Invalid Input.");
        }
    }
}
void create()
{   
    char ch;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter first node:");
    scanf("%d",&temp->data);
    temp->prev=temp->next=NULL;
    start=last=temp;
    printf("Do you want to enter more(y/n): ");
    while((getchar())!='\n');
    scanf("%c",&ch);
    
    while(ch=='y')
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the next node:");
        scanf("%d",&temp->data);
        last->next=temp;
        temp->prev=last;
        last=temp;
        
        printf("Do you want to enter more data(y/n): ");
        while((getchar())!='\n');
        scanf("%c",&ch);
    }
    last -> next=NULL;
}
void insert_begin()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the first node:");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
        temp->prev=temp->next=NULL;
        start=last=temp;
    
    }
    else{
        start->prev=temp;
        temp->next=start;
        temp->prev=NULL;
        start=temp;
    }
    
}
void insert_last()
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the first node:");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
        temp->prev=temp->next=NULL;
        start=last=temp;
    
    }
    else{
       last->next=temp;
       temp->prev=last;
       temp->next=NULL;
       last=temp;
    }
    
}
    
void insert_specific()
{ 
  int x;
  struct node *temp=start;
  struct node *temp1=(struct node*)malloc(sizeof(struct node));
  printf("enter the first node:");
  scanf("%d",&temp1->data);
  printf("enter the node after which do u want to insert:");
  scanf("%d",&x);
  while(temp->data!=x)
  {
      temp=temp->next;
  }
  temp1->next=temp->next;
  temp->next->prev=temp1;
  temp->next=temp1;
  temp1->prev=temp;
  
}
void delete_first()
{
    struct node *temp=start;
    if(start==NULL)
    {
        printf("list is empty.");
        
    }
    else if(start->next==NULL)
     start=last=NULL;
    
    else 
        start=start->next;
        start->prev=NULL;
        free(temp);
    }

void delete_last()
{
    struct node *temp=last;
    if(start==NULL)
    {
        printf("list is empty.");
        
    }
    else if(start->next==NULL)
        start=last=NULL;
        
    
    else {
        last=last->prev;
        last->next=NULL;
        
    }
    free(temp);
}
void delete_specific()
{
    int x;
    struct node *temp=start;
    printf("enter the node which do u want to delete:");
    scanf("%d",&x);
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
} 
void display_forward()
{
    struct node *temp=start;
    if(start==NULL)
    {
        printf("no nodes in the list.");
        
    }
    else {
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            if (temp->next != NULL) //for formatting of diaplay
            printf("->");
            temp=temp->next;
        }
    }
}
void display_backward()
{
    struct node *temp=last;
    if(start==NULL)
    {
        printf("no nodes in the list.");
        
    }
    else {
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            if (temp->prev != NULL) //for formatting of diaplay
            printf("->");

            temp=temp->prev;
        }
    }
        
    
}
void length(){
    struct node *temp=start;
    if(start==NULL){
        printf("\n No nodes in the linked list.\n");
    }
    else{
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        printf("The length of list is: %d",count);
    }
}
