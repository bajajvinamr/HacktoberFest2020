#include <bits/stdc++.h>
using namespace std;

struct Node
{
    
    int data;
    Node *left,*right;
   
    
};

Node *newNode(int key)
    {
        Node *temp = new Node(); 
        temp->data  = key;
        temp->left = temp->right = NULL;
        return temp;
    }

Node* insert(Node* root,int key) 
{
    
    if(root==NULL)
    {
        root = newNode(key);
        return root;
        
    }
    if(root->data>key)
    {
        if(root->left == NULL)
        {
            root->left = newNode(key);       
            return root;     
          
        }
        insert(root->left,key);
    }
    if(root->data<=key)
    {
        if(root->right == NULL)
        {
            root->right = newNode(key);
            return root;
            
        }
        insert(root->right,key);
    }
return root;
}
void printInorder(Node *root)
{
    
    if(root == NULL)
    return ;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

void printPreorder(Node *root)
{
     if(root == NULL)
    return ;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
    
}

void printPostorder(Node *root)
{
    if(root == NULL)
    return ;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
    
}
void bfs(Node* root)
{
    if(root == NULL)
    return;
    queue <Node *> q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);


    }

}
int main()
{
    Node *root = NULL;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

    
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 4);
    root = insert(root, 8);

   // root = start;
    //dfs
    cout<<"Inorder: "<<endl;
    printInorder(root);

    cout<<endl;
    cout<<"Preorder: "<<endl;
    printPreorder(root);
    cout<<endl;
    cout<<"Postorder: "<<endl;
    printPostorder(root);
    cout<<endl;
    //bfs
    cout<<"bfs"<<endl;
    bfs(root);
    return 0;
}