# Node class 
class Node: 
  
    # Function to initialise the node object 
    def __init__(self, data): 
        self.data = data  # Assign data 
        self.next = None  # Initialize next as null 
  
  
# Linked List class contains a Node object 
class LinkedList: 
    
    # Function to initialize head 
    def __init__(self): 
        self.head = None
  
    # This function prints contents of linked list 
    # starting from head 
    def printList(self): 
        temp = self.head 
        while (temp): 
            print (temp.data) 
            temp = temp.next
            
    def insert_element(self,data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while(temp.next):
            temp = temp.next
        temp.next = newNode
  
  
# Code execution starts here 
if __name__=='__main__': 
  
    # Start with the empty list 
    llist = LinkedList() 
  
    llist.insert_element(1)
    llist.insert_element(2)
    llist.insert_element(3)
  
    llist.printList() 
