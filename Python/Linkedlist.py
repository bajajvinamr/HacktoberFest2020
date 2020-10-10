class Node:
  def __init__(self, data = None, next=None): 
    self.data = data
    self.next = next

class LinkedList:
  def __init__(self):  
    self.head = None
  def insert(self, data):
    newNode = Node(data)
    if(self.head):
      current = self.head
      while(current.next):
        current = current.next
      current.next = newNode
    else:
      self.head = newNode
  def printLL(self):
    current = self.head
    while(current):
      print(current.data)
      current = current.next
  def removeNthFromEnd(self, n):
    temp = self.head
    k=0
    while temp!=None:
        k+=1
        temp=temp.next
    pos=k-n
    curr_pos=0
    prev=None
    temp=self.head
    while curr_pos!=pos:
        prev=temp
        temp=temp.next
        curr_pos+=1
    if prev:
        prev.next=temp.next  
    else:
        self.head=self.head.next
    return self.head 
keys = list(map(int, input().split(" ")))
LL = LinkedList()
for key in keys:
    LL.insert(key)
#LL.printLL()
x=int(input())
LL.removeNthFromEnd(x)
LL.printLL()