# Program to find an element using linear search


def linear_search(arr, x):

    for i in range(len(arr)):

        if arr[i] == x:
            return i

    return -1


arr = [2, 1, 3, 5, 6, 7]
x = 3
print(f'Position of element {x} is at {linear_search(arr, x)}')
