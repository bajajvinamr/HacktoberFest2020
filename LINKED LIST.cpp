#include<iostream>
using namespace std;

struct node{
	int data;
	node * next;
}*first=NULL,*last=NULL;


void create(int x,node *p){
	node *t=new node;
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=last=t;
	}
	else
	{
		last->next=t;
		last=t;
	}
	
	
}

void display(node *p){
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
}

void recursive_display(node* p){
	
	if(p!=NULL){
		cout<<p->data<<" ";
		recursive_display(p->next);
	}
	
}

void recursive_reverse_display(node *n){
	if(n!=NULL){
		recursive_reverse_display(n->next);
		cout<<n->data<<" ";
	}
}

int counter(node *p){
	int count=0;
	while(p){
		p=p->next;
		count++;
	}
	return count;
}

int max(node *p){
	int max=INT_MIN;
	while(p){
		if(p->data > max)
		max=p->data;
		p=p->next;
	}
	return max;
}

int recursive_sum(node *p){
	if(p)
	return recursive_sum(p->next)+p->data;
	else
	return 0;
}
int search(node *p,int key){
	int pos=1;
	while(p){
		
		if(p->data==key)
		{
		goto x;
	}
	pos++;
	p=p->next;
	}
	
	x:
		if(pos!=1){
			
		}
}

void insert(node *p,int x,int pos){
	node *t=new node;
	t->data=x;
	if(pos==0){
		t->next=first;
		first=t;
	}
	else if(pos>0){
		for(int i=0;i<pos-1&&p;i++){
			p=p->next;
			if(p){
				t->next=p->next;
				p->next=t;
			}
			
		}
	}
	display(first);
}

void insert_sorted(node * p,int x){
	node *t=new node;
	node *q=new node;
	t->data=x;
	if(first==NULL)
	{
		first=t;
		t->next=NULL;
	}
	else{
	
	while(p && (p->data<x)){
		q=p;
		p=p->next;
	}
	t->next=q->next;
	q->next=t;
}

cout<<"\n\nThe new Array is:";
display(first);
}
int main(void){
	int n,x;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x;
		create(x,first);
	}
	cout<<"The linked list is\n";
	recursive_display(first);
	cout<<"\n\nThe reversed linked list is:\n";
	recursive_reverse_display(first);
	cout<<"\n\nTotal number of nodes present are:"<<counter(first);
	cout<<"\n\nThe sum of the nodes data is:"<<recursive_sum(first);
	cout<<"\n\nThe max element in the linked list:"<<max(first);
	cout<<"\n\nEnter the element to be searched in the linked list:";
	int item;
	cin>>item;
	cout<<"Element is present at the pos:"<<search(first,item);
	cout<<"\n\nThis is to insert a new node";
	cout<<"\nEnter the value and the pos:";
	int pos;
	cin>>x>>pos;
	insert(first,x,pos);
	cout<<"\n\nThis inserting in a sorted linked list:";
	cout<<"\nEnter the value to be stored:";
	cin>>x;
	insert_sorted(first,x);
}
