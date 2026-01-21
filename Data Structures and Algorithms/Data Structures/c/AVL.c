/*
File Name:
Author: Shrida Kalamkar

*/

#include<stdio.h>
#include<stdlib.h>
//Problem : AVL Tree Implementation


//Node Structure Declaration

struct Node{
        int data;
        struct Node *left;
        struct Node *right;
        int height;

    }*root=NULL;

//Calculate Height

int Nodeheight(struct Node *p){
    int hl,hr;
    hl=p && p->left?p->left->height:0;
    hr=p && p->right?p->right->height:0;
    return hl>hr?hl+1:hr+1;

}

//Calculate Balance Factor
int balanceFactor(struct Node *p){
    int hl,hr;
    hl=p && p->left?p->left->height:0;
    hr=p && p->right?p->right->height:0;
    return hl-hr;
}



//Right Rotation
struct Node *RRotation(struct Node *p){
    struct Node *pl=p->left;
    struct Node *T2=pl->right;

    pl->right=p;
    p->left=T2;


    p->height=Nodeheight(p);
    pl->height=Nodeheight(pl);

    if(root==p)
        root=pl;

    return pl;

}

//Left Rotation
struct Node *LRotation(struct Node *p){
    //Write your code here
    struct Node *pr=p->right;
    struct Node *T1=pr->left;

    pr->left = p;
    p->right = T1;

    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);

    if(root==p)
        root = pr;

    return pr;

}

//Left-Right Rotation

struct Node *LRRotation(struct Node *p){
    //Write your code here
    struct Node *pl=p->left;
    struct Node *T1=pl->right;
    struct Node *T2=T1->left;
    
    pl->right = T2;
    T1->left = pl;
    p->left = T1;

    p->left = T1->right;
    T1->right = p;

    if(p==root)
        root = T1;

    return T1;


}

//Right-Left Rotation
struct Node *RLRotation(struct Node *p){
    //write your code here
    struct Node *pr=p->right;
    struct Node *T1=pr->left;
    struct Node *T2=T1->right;

    pr->left =  T2;
    T1->right = pr;
    p->right = T1;


    p->right = T1->left;
    T1->left = p;

    if(p==root)
        root = T1;

    return T1;

}


//Insert

struct Node *RInsert(struct Node *p,int key){
    struct Node *temp=NULL;

    if(p==NULL){
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=key;
        temp->height=1;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(key < p->data)
        p->left=RInsert(p->left,key);
    else if(key > p->data)
        p->right=RInsert(p->right,key);

        p->height=Nodeheight(p);

        if(balanceFactor(p)==2 && balanceFactor(p->left)==1)
            return RRotation(p);
        else if(balanceFactor(p)==-2 && balanceFactor(p->right)==-1)
            return LRotation(p);
        else if(balanceFactor(p)==-2 && balanceFactor(p->right)==1)
            return RLRotation(p);
        else if(balanceFactor(p)==2 && balanceFactor(p->left)==-1)
            return LRRotation(p);

        return p;
}

struct Node * Inorder(struct Node *p){
    if(p == NULL)
        return NULL;
    Inorder(p->left);
    printf("%d,",p->data);
    Inorder(p->right);
    return p;

}


int main()
{
    root=RInsert(root,50);
    RInsert(root,20);
    RInsert(root,10);
    RInsert(root,30);
    RInsert(root,40);
    Inorder(root);

    //Accept the values from user
	return 0;

}