#include<bits/stdc++.h>
using namespace std;

//*** to intialize a node ***//
struct Node {
	int data;
	Node* left;
	Node* right;
};


//*** to create a new node ***//
Node* newNode(int key) 
{
	Node* temp=new Node();
	temp->data=key;
	temp->left=temp->right=NULL;
}

//*** function to print inorderBST ***//
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 
			
	printInorder(node->left); 
	
	cout<<node->data<<" "; 

	printInorder(node->right); 

}

//*** function to insert a numer non-recursively ***//
Node* insert(Node* root, int data)
{
	Node* value=newNode(data);
			
	Node *temp_parent=NULL, *temp=root;
	
	while(temp!=NULL)
	{
		temp_parent=temp;
		if(temp->data > data)					//iterating loop untill we reach at a leaf node of tree
			temp=temp->left;
		else
			temp=temp->right;
		
	}
	if (temp_parent==NULL)
		temp_parent=value;
	else if(temp_parent->data >data)
		temp_parent->left= value;
	else
		temp_parent->right= value;
	
	return temp_parent;
	
}

int main()
{
	int n,i;
	cout<<"Enter number of nodes:- ";
	cin>>n;
	cout<<endl;
	
	int a[n];
	cout<<"Enter values of n nodes:- ";
	for(i=0;i<n;i++)
		cin>>a[i];
	
		
	cout<<endl;
	
	Node* root=NULL;
	root=insert(root, a[0]);
	for(i=1;i<n;i++)
	{
		insert(root, a[i]);												//insert non-recursivey
	}
	cout<<endl;
	
	
	cout<<"InOrder Travesal of BST:- ";
	printInorder(root);													//print indrder
	cout<<endl<<endl;
}