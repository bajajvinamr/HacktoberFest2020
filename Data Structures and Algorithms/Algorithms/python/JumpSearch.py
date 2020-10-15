#Python implementation for jump search

import math
def jump_search(arr, x): # the total number of comparisons in the worst case will be ((n/m) + m-1).
	n=len(arr)
	m=math.sqrt(n)                     # The value of the function ((n/m) + m-1) will be minimum when m = √n. Therefore, the best step size is m = √n.
	prev=0
	while arr[int(min(m, n)-1)] < x:  #in this loop we just jump over indexes by an effective jump(m = √n, proved in above comment)
		prev = m
		m+=m
		if prev>n:
			return -1
	while arr[int(prev)] < x:  #new loop for linear search where we check those positions which were skipped during the above "jumping" loop
		prev+=1
		if prev==min(m, n):
			return -1

	if arr[int(prev)] == x:
		return int(prev)+1

	return -1
  
array = list(map(int, input().split()))
x = int(input())
res = jump_search(array, x)
if res>-1:
  print("Element found at index: ", res)
else:
  print("Element not found!!")
