#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node
{ int data;
  struct node * next,*prev;
}*head=NULL,*last,*ptr,*ptr1;
void del_beg()
{if(head==NULL)
  printf("Underflow\n");
 else if(head->next==head)
  {ptr1=head;
   head=NULL;
   free(ptr1);
   }
 else
  {ptr1=head;
   last=head->prev;
   last->next=head->next;
   head->next->prev=last;
   head=head->next;
   free(ptr1);
  }
}
void del_end()
{if(head==NULL)
  printf("Underflow\n");
 else if(head->next==head)
  {ptr1=head;
   head=NULL;
   free(ptr1);
   }
 else
  {last=head->prev;
    last->prev->next=head;
    head->prev=last->prev;
    free(last);
  }
 }
void del_pos()
{ int pos,cnt=1;
  printf("Enter position :");
   scanf("%d",&pos);
 if(head==NULL)
   printf("Underflow\n");
 else
 { if(pos==1)
   del_beg();
   else
    { ptr=head;
      while(cnt!=pos-1)
      { ptr=ptr->next;
       cnt++;
       }
       ptr1=ptr->next;
       ptr1->next->prev=ptr;
       ptr->next=ptr1->next;
       free(ptr1);
    }
 }
}
void ins_beg()
{ struct node *  ptr=(struct node *)malloc(sizeof(struct node *));
 printf("Enter data : ");
 scanf("%d",&ptr->data);
 if(head==NULL)
  {head=ptr;
  head->next=head;
  head->prev=head;
  }
 else
 { last=head->prev;
    ptr->next=head;
    ptr->prev=last;
    last->next=ptr;
    head->prev=ptr;
   head=ptr;
 }
}
void ins_pos()
{int pos,cnt=1;
printf("Enter pos : ");
scanf("%d",&pos);
if(pos==1)
  ins_beg();
else
 {ptr=(struct node*)malloc(sizeof(struct node*));
  printf("Enter data : ");
  scanf("%d",&ptr->data);
  ptr1=head;
  while(cnt!=pos-1)
  {cnt++;
   ptr1=ptr1->next;
  }
  ptr->prev=ptr1;
  ptr->next=ptr1->next;
  ptr1->next->prev=ptr;
  ptr1->next=ptr;
 }
}
void ins_end()
{ptr=(struct node *)malloc(sizeof(struct node *));
 printf("Enter data : ");
 scanf("%d",&ptr->data);
 if(head==NULL)
 { head=ptr;
  head->next=head;
  head->prev=head;
  }
 else
 { ptr->next=head;
  ptr->prev=head->prev;
  head->prev->next=ptr;
  head->prev=ptr;
 }
}
void display()
{ptr=head;
 if(ptr==NULL)
  printf("Empty\n");
 else
 {while(ptr->next!=head)
   { printf("%d->",ptr->data);
    ptr=ptr->next;
    }
 printf("%d\n",ptr->data);
 }
}
int main()
{ int ch;
 while(1)
 {printf("1.Insert At Start 2.Insert At End 3.Insert At Position 4.Display\n 5.Delete At Start 6.Delete At Position 7.Delete At End 8.Exit\nEnter choice:");
  scanf("%d",&ch);
  switch(ch)
   {case 1 :  ins_beg();
	       break;
    case 2 : ins_end();
		 break;
    case 3: ins_pos();
	    break;
    case 4 : display();
	     break;
   case 5: del_beg();
	    break;
   case 6: del_pos();
	    break;
    case 7 :del_end();
	    break;
    case 8: exit(0);
    default: printf("Invalid choice\n");
   }
 }
 return 0;
}
