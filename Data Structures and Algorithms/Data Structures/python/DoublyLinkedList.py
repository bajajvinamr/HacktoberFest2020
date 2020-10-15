# Defining what a node is, with attributes of data, next, and prev
class Node:
    def __init__(self, data):
        self.item = data
        self.next = None
        self.prev = None

# Definition of a DoublyLinkedList, using Node class
class DoublyLinkedList:
    def __init__(self):
        self.start_node = None

    def traverse_list(self):
        if self.start_node is None:
            print("There are no elements!")
            return
        else:
            n = self.start_node
            while n is not None:
                print(n.item , " ")
                n = n.next
    
    def insert_at_start(self, data):
        if self.start_node is None:
            new_node = Node(data)
            self.start_node = new_node
            return
        new_node = Node(data)
        new_node.next = self.start_node
        self.start_node.prev = new_node
        self.start_node = new_node


# Initializing a DoublyLinkedList
example = DoublyLinkedList()

example.insert_at_start(10)
example.insert_at_start(5)
example.insert_at_start(18)

example.traverse_list()