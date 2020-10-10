//Java Program to create a Simple Binary Tree 

class Node 
{ 
    int index; 
    Node lt, rt; 
  
    public Node(int item) 
    { 
        index = item; 
        lt = rt = null; 
    } 
} 

class binaryTree 
{ 
    // rootNode 
    Node rootNode; 
  
    // Constructor
    binaryTree(int index) 
    { 
        rootNode = new Node(index); 
    } 
    //Constructor
    binaryTree() 
    { 
        rootNode = null; 
    } 
  
    public static void main(String[] args) 
    { 
        binaryTree bt = new binaryTree(); 
        bt.rootNode = new Node(1);  
        bt.rootNode.lt = new Node(2); 
        bt.rootNode.rt = new Node(3); 
        bt.rootNode.lt.lt = new Node(4); 
        
    } 
}