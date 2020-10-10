#include <iostream>
using namespace std;
#include<vector>
class node{

public: 
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int d){
    if(root == NULL){
        return new node(d);
    }
    if(d<=root->data){
        root->left = insert(root->left,d);
    }
    else 
        root->right = insert(root->right,d);

    return root;
}

node* create(){
    node* root= NULL;
    int n;
    cin>>n;
    while(n--){
        int d;
        cin>>d;
        root = insert(root,d);
    }
    return root;
}
vector<int>v;

void range_BST(node* root, int l, int h){

    if(root==NULL){
        return;
    }
    if(l < root->data){
        range_BST(root->left,l,h);
    }

    if( l<= root->data && root->data <= h){
        //v.push_back(root->data);
        cout<<root->data<<" ";
    }

    if(h > root->data){
        range_BST(root->right,l,h);
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

int t;
cin>>t;
while(t--){
    node* root = create();
    int l,h;
    cin>>l>>h;
    cout<<"# Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"# Nodes within range are : ";
    range_BST(root,l,h);
    // for(auto i: v)
    //     cout<<i<<" ";
    cout<<endl;
}
return 0;
}
