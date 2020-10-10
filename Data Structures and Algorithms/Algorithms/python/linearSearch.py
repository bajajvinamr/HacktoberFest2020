# Program to find an element using linear search


def linear_search(arr, x):

    for i in range(len(arr)):

        if arr[i] == x:
            return i

    return -1


print("Enter no. of elements")
n = int(input())

print("Enter elements")
arr = []
for i in range(n):
    arr.append(int(input())

print("Enter no. to find")               
x = int(input())
               
print(f'Position of element {x} is at {linear_search(arr, x)}')
