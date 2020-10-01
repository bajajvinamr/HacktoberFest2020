# Python program for implementation of Bubble Sort
# Time complexity is O(n^2) which is very slow, prefer the inbuilt sort function over it.
def sortsort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
arr = [10, 20, 11, 0, 15, 19]

sortsort(arr)

print ("The sorted array is:")
for i in range(len(arr)):
    print ("%d" %arr[i]), 
