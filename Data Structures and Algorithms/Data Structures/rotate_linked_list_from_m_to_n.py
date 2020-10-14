# Python3 implementation of the above approach
import math

# Definition of node of linkedlist


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# This function take head pointer of list,
# start and end points of sublist that is
# to be rotated and the number k and
# rotate the sublist to right by k places.


def rotateSubList(A, m, n, k):
    size = n - m + 1

    # If k is greater than size of sublist then
    # we will take its modulo with size of sublist
    if (k > size):
        k = k % size

    # If k is zero or k is equal to size or k is
    # a multiple of size of sublist then list
    # remains intact
    if (k == 0 or k == size):
        head = A
        while (head != None):
            print(head.data)
            head = head.next

        return

    link = None  # m-th node
    if (m == 1):
        link = A

    # This loop will traverse all node till
    # end node of sublist.
    c = A  # Current traversed node
    count = 0  # Count of traversed nodes
    end = None
    pre = None  # Previous of m-th node
    while (c != None):
        count = count + 1

        # We will save (m-1)th node and later
        # make it point to (n-k+1)th node
        if (count == m - 1):
            pre = c
            link = c.next

        if (count == n - k):
            if (m == 1):
                end = c
                A = c.next

            else:
                end = c

                # That is how we bring (n-k+1)th
                # node to front of sublist.
                pre.next = c.next

        # This keeps rest part of list intact.
        if (count == n):
            d = c.next
            c.next = link
            end.next = d
            head = A
            while (head != None):
                print(head.data, end=" ")
                head = head.next

            return

        c = c.next

# Function for creating and linking new nodes


def push(head, val):
    new_node = Node(val)
    new_node.data = val
    new_node.next = head
    head = new_node
    return head


# Driver code
if __name__ == '__main__':
    head = None
    head = push(head, 70)
    head = push(head, 60)
    head = push(head, 50)
    head = push(head, 40)
    head = push(head, 30)
    head = push(head, 20)
    head = push(head, 10)
    tmp = head
    print("Given List: ", end="")
    while (tmp != None):
        print(tmp.data, end=" ")
        tmp = tmp.next

    print()

    m = 3
    n = 6
    k = 2
    print("After rotation of sublist: ", end="")
    rotateSubList(head, m, n, k)
