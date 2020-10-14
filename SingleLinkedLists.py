# Single Linked List Class
# contains pointers to head 
# Linked List Nodes contain data objects and pointers to next Linked List Node (or None)

class LListNode:
    def __init__(self, data, nextLListNode):
        self.data = data
        self.next = nextLListNode
    def __str__(self):
        return str(self.data)

class LList:
    def __init__(self):
        self.head = None
    def __str__(self):
        a=''
        if self.head!=None:
            node=self.head
            a=str(node)
            while node.next!=None:
                a+=', '+str(node.next)
                node=node.next
        return a

    def insert_end(self, data):
        new_node = LListNode(data, None)
        if self.head is None:     # empty LList
            self.head = new_node
        else:
            node = self.head      # non-empty list
            while node.next is not None:
                node = node.next
            node = new_node

    def remove_end(self):
        if self.head is None :     # empty LList
            return None
        node = self.head  # more than one node in the LList general case
        if node.next is None:  # one node in LList
                                    # (so removing it is a special case)
            data = node.data
            self.head = None
            return data
        while node.next.next is not None:
            node = node.next
        data = node.next
        node.next = None
        return data

    def insert_front(self, data):
        new_node = LListNode(data, None)
        if self.head is None:     # empty LList
            self.head = new_node
        else:
            node = self.head      # non-empty list
            third = node.next
            node.next = new_node
            new_node.next = third

    def remove_front(self):
        if self.head is None :     # empty LList
            return None
        node = self.head  # more than one node in the LList general case
        if node.next is None:  # one node in LList
                                    # (so removing it is a special case)
            data = node.data
            self.head = None
            return data
        temp = node.next
        node.next = temp.next
        return data

list = LList()
for x in range(1,6):
    list.insert_end(x)

print("---initial list---")
print(list)
print('---insert 27 at end---')
list.insert_end(27)
print(list)
print('---insert 42 at end---')
list.insert_end(42)
print(list)
print('---remove two from tail---')
z= list.remove_end()
p= list.remove_end()
print(z, p)
print('---print remaining list---')
print(list)

