def binarySearch(arr, x): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
  
        if arr[mid] < x: 
            low = mid + 1
  
        elif arr[mid] > x: 
            high = mid - 1

        else: 
            return mid 

    return -1

n = int(input("Enter the length of the array: "))
arr = []

for i in range(n):
    x = int(input())
    arr.append(x)
y = int(input("Enter the key to be searched :"))

idx = binarySearch(arr, y)

if idx == -1:
    print("The key is not present")
else:
    print("The key is present in index {}".format(idx))
