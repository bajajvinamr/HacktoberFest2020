#include<iostream>
#include<stack>

using namespace std;

struct bstnode ;
typedef bstnode* bstptr;

struct queue{
	int s=50;
	int r=-1;
	int f=-1;
	bstptr el[50];
};

void enque(struct queue &q,bstptr x)
{
	if((q.r+1)%q.s==q.f)
	cout<<"queue full !";
	else{
		if(q.f==-1)
		{
			q.f=0;
			q.r=0;
		}
		else{
			q.r=(q.r+1)%q.s;
		}
		q.el[q.r]=x;
	}
}

bstptr dequeue(struct queue &q)
{
	if(q.f==-1)
	cout<<"empty!";
	else{
		bstptr t;
		if(q.f==q.r)
		{
			t=q.el[q.f];
			q.f=-1;q.r=-1;
		}
		else{
		    
			t=q.el[q.f];
			q.f=(q.f+1)%q.s;
		}
		return t;
	}
}

bool isqempty(queue q)
{
    if(q.f==-1)
    return true;
    return false;
}

struct bstnode{
	bstnode* lchild=NULL;
	int data;
	bstnode* rchild=NULL;
};

void insert(bstptr &T,int k)
{
	if(T==NULL)
	{
		T = new bstnode;
		T->data = k;
		return;
	}
	else{
		if(k<T->data)
		insert(T->lchild,k);
		else if(k>T->data)
		insert(T->rchild,k);
	}
}

void createbst(bstptr &T)
{
	int k;cin>>k;
	while(k!=-1)
	{
		insert(T,k);
		cin>>k;
	}
}

//////////////////MAIN CODE/////////////////////
void levelorder(bstptr T)
{
    queue temp_node;
    enque(temp_node,T);
    while(!isqempty(temp_node))
    {
        bstptr T1=dequeue(temp_node);
        cout<<T1->data<<" ";
        if(T1->lchild)
        enque(temp_node,T1->lchild);
        if(T1->rchild)
        enque(temp_node,T1->rchild);
    }
    cout<<endl;
}
 
void revlevelorder(bstptr T)
{
     queue temp_node;
     stack <int> s;
     enque(temp_node,T);
     bool cl=0;
     int nxtcount=2;
     int tmp=nxtcount;
     while(!isqempty(temp_node))
     {
         bstptr T1=dequeue(temp_node);
         s.push(T1->data);
         if(T1->rchild)
         enque(temp_node,T1->rchild);
         if(T1->lchild)
         enque(temp_node,T1->lchild);
     }
     while(!s.empty())
     {
         cout<<s.top()<<" ";
         s.pop();
     }
     cout<<endl;
}

void sqlo_acw(bstptr T)
{
     queue temp_node;
     stack<bstptr> s;
     enque(temp_node,T);
     bool cl=0;
     int nxtcount=2;
     int tmp=nxtcount,level=1;
     while(!isqempty(temp_node))
     {
         bstptr T1=dequeue(temp_node);
         cout<<T1->data<<" ";
         
         if(level%2!=0){
         if(T1->rchild)
         s.push(T1->rchild);nxtcount--;
         if(T1->lchild)
         s.push(T1->lchild);nxtcount--;
     	 }
     	 else{
     	 if(T1->lchild)
         s.push(T1->lchild);nxtcount--;
     	 if(T1->rchild)
         s.push(T1->rchild);nxtcount--;
		 }
         if(nxtcount==0)
         {
         	nxtcount=tmp*2;
         	tmp*=2;
         	level++;
            while(!s.empty())
     		{
        	 enque(temp_node,s.top());
        	 s.pop();
     		}
		 }
     }
     cout<<endl;
}

void sqlo_cw(bstptr T)
{
     queue temp_node;
     stack<bstptr> s;
     enque(temp_node,T);
     bool cl=0;
     int nxtcount=2;
     int tmp=nxtcount,level=0;
     while(!isqempty(temp_node))
     {
         bstptr T1=dequeue(temp_node);
         cout<<T1->data<<" ";
         
         if(level%2!=0){
         if(T1->rchild)
         s.push(T1->rchild);
         if(T1->lchild)
         s.push(T1->lchild);nxtcount-=2;
     	 }
     	 else{
     	 if(T1->lchild)
         s.push(T1->lchild);
     	 if(T1->rchild)
         s.push(T1->rchild);nxtcount-=2;
		 }
         if(nxtcount==0)
         {
         	nxtcount=tmp*2;
         	tmp*=2;
         	level++;
            while(!s.empty())
     		{
        	 enque(temp_node,s.top());
        	 s.pop();
     		}
		 }
     }
     cout<<endl;
}

int main()
{
    bstptr T=NULL;
    createbst(T);
    levelorder(T);
    //reverse level order
    revlevelorder(T);
    //squirrel clockwise printing
    sqlo_cw(T);
    //squirrel anticlock wise
    sqlo_acw(T);
    //Alternate odd-level reversal level order  same as Squirrel level order (clock-wise start):
    sqlo_cw(T);
    //Alternate odd-level reversal level order same as Alternate even-level reversal level order
    sqlo_acw(T);
}
