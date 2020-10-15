"""
Stack data structure
"""
class Stack():
    # LIFO Stack implementation using a Python list as underlying storage

    def __init__(self):
        # create an empty stack
        self.items = [] # an empty list is created when we create a stack object

    def is_empty(self):
        # return True if stack is empty
        return self.items == [] # or len(self.items) == 0

    def len(self):
        # return number of elements in the stack
        return len(self.items)

    def push(self, item):
        # add element item to the top of the stack
        self.items.append(item) # new item stored at end of list

    def pop(self): # return the last/top element in stack and then remove it from stack
        if self.is_empty():
            raise Empty("Stack is empty")
        else:
            return self.items.pop() # using list's pop built-in function to remove last/top item from stack

    def top(self): # return the last/top element in stack
        """Return (but do NOT remove) the element at the top of the stack
        """
        if not self.is_empty():
            return self.items[-1] # last item in the list
        else:
            print("Stack is empty")

    def get_stack(self):
        return self.items #return all items int stack