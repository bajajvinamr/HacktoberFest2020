n=int(input())
matrix=[]

for i in range(0,n):
  a=list(map(int,input().split()))
  matrix.append(a)
p=n
q=n
x=0
y=0
c=0
t=n*n

while(x<p and y<q): 
  if(c==t): 
    break
    
  for i in range(x,p): 
    print(matrix[i][y],end = " ") 
    c+=1
    
  y+=1 
  
  if(c==t):
    break
    
  for i in range(y,q): 
    print(matrix[p-1][i],end=" ") 
    c+= 1
    
  p-=1
  
  if(c==t): 
    break
    
  if(x<p): 
    for i in range(p-1,x-1,-1): 
      print(matrix[i][q-1],end= " ") 
      c+= 1
    q-=1
    
  if(c==t): 
    break
    
  if (y<q) : 
    for i in range(q-1,y-1,-1) : 
      print(matrix[x][i],end = " ") 
      c+=1
      
  x+=1
