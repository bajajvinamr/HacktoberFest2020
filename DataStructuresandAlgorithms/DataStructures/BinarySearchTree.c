#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data=item;
    t->left=t->right=NULL;
}

struct node* insert(struct node* node, int data )
{
    if(node==NULL)
    {
        return newNode(data);
    }

    if(data < node->data)
    {
        node->left=insert(node->left,data);
    }
    else if(data> node->data)
    {
        node->right=insert(node->right,data);
    }

    return node;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

/*void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}*/

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}



int main()
{
    struct node *root = NULL;
    root=insert(root,83);
    insert(root,25);
    insert(root,11);
    insert(root,12);
    insert(root,32);
     insert(root,95);
      insert(root,46);
       insert(root,87);
        insert(root,68);
         insert(root,100);
    
    //inorder(root);
    printf("\n");
    //preorder(root);
    printf("\n");
    postorder(root);

}