li=[int(x) for x in input().split()] # input list using comprehension

n=len(li)

for i in range (n-1):# take one element
  minEle=li[i]
  ind=i
  for j in range(i+1,n): 
    # 

    if li[j]<minEle: # compare it with all elements further in the list
      minEle=li[j]
      ind=j
  li[i],li[ind]=minEle,li[i] # replace the element by minimum element found from i+1 to n indices
  
print(li) # print the sorted list
