# Program to add two matrices using nested loop
A=[]
n=int(input("Enter N for N x N matrix : "))         #3 here
#use list for storing 2D array
#get the user input and store it in list (here IN : 1 to 9)
print("Enter the element ::>")
for i in range(n): 
   row=[]                                        #temporary list to store the row
for j in range(n): 
   row.append(int(input()))                #add the input to row list
A.append(row)                               #add the row to the list
print(A)
# [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
#Display the 2D array
print("Display Array In Matrix Form")
for i in range(n):
   for j in range(n):
      print(A[i][j], end=" ")                  #new line
   print() 
B=[]
n=int(input("Enter N for N x N matrix : "))        #3 here
#use list for storing 2D array
#get the user input and store it in list (here IN : 1 to 9)
print("Enter the element ::>")
for i in range(n): 
   row=[]                                        #temporary list to store the row
   for j in range(n): 
      row.append(int(input()))             #add the input to row list
   B.append(row)                            #add the row to the list
print(B)
# [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
#Display the 2D array
print("Display Array In Matrix Form")
for i in range(n):
   for j in range(n):
      print(B[i][j], end=" ")
   print()                                            #new line
result = [[0,0,0], [0,0,0], [0,0,0]] 
# iterate through rows 
for i in range(n):    
# iterate through columns 
for j in range(len(A[0])): 
   result[i][j] = A[i][j] + B[i][j] 
print("Resultant Matrix is ::>")
for r in result: 
   print("Resultant Matrix is ::>",r)
