
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};



struct node *newNode(int a){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}


int height(struct node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
   
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}

int getBalance(struct node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}


struct node *rightRotate(struct node *y)  
{  
    struct node *a = y->left;  
    struct node *temp = a->right;  

    
    a->right = y;  
    y->left = temp;  
  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    a->height = max(height(a->left), 
                    height(a->right)) + 1;  
  
    return a;  
}  

struct node *leftRotate(struct node *y){
    struct node *a = y->right;
    struct node *temp = a->left;

    a->left = y;
    y->right = temp;

        y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    a->height = max(height(a->left), 
                    height(a->right)) + 1;  
  
    return a; 
}



struct node* Insert(struct node* root, int a){
    
    if(root == NULL)
    {
       root = newNode(a);
    }
    else if(a < root->data)
    {
       root->left = Insert(root->left,a);
    }
    else if(a > root->data)
    {
        root->right = Insert(root->right,a);
    }
    else 
    {
        return root;
    }


    
    root->height = 1 + max(height(root->left),  
                        height(root->right));  
  
  
    int balance = getBalance(root);  
  
   
    if (balance > 1 && a < root->left->data)  
        return rightRotate(root);  
  
    if (balance < -1 && a > root->right->data)  
        return leftRotate(root);  
    
    if (balance > 1 && a > root->left->data)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
   
    if (balance < -1 && a < root->right->data)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  

}

struct node * minValue(struct node* node)  
{  
    struct node* current = node;  
  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}


struct node* Delete(struct node* root, int key)  
{  
 
    if (root == NULL)  
        return root;  

    if ( key < root->data )  
        root->left = Delete(root->left, key);  

    else if( key > root->data )  
        root->right = Delete(root->right, key);  
 
    else
    {   
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            struct node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {   
            struct node * temp = minValue(root->right);  
 
            root->data = temp->data;  
  
            // Delete the inorder successor  
            root->right = Delete(root->right,  
                                     temp->data);  
        }  
    }  
 
    if (root == NULL)  
    return root;  

    root->height = 1 + max(height(root->left),  
                           height(root->right));  
 
    int balance = getBalance(root);  
 
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  


void print(struct node *root)  
{  
    if(root != NULL)  
    {  
        printf("%d ",root->data);  
        print(root->left);  
        print(root->right);  
    }  
} 


int main()  
{  
    struct node *root = NULL;  
 
//Inserting elements
    root = Insert(root, 10);  
    root = Insert(root, 20);  
    root = Insert(root, 30);  
    root = Insert(root, 40);  
    root = Insert(root, 50);  
    root = Insert(root, 25);  

    print(root);

    printf("\n");

//Deleting elemets
    root = Delete(root,10);
    root = Delete(root,30);
       
    print(root);  
      
    return 0;  
} 