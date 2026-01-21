n= int(input("enter n1 in n1*m1 matrix"))
m= int(input("enter m1 in n1*m1 matrix"))
U=[]
for i in range(n):
    U.append([])
for i in range(n):
    for j in range(m):
        U[i].append(j)
        U[i][j]=0
        print("row entry:",i+1,"column entry:",j+1)
        U[i][j]=int(input())
print(U)
o= int(input("enter n2 in n2*m2 matrix"))
p= int(input("enter m2 in n2*m2 matrix"))
K=[]
for i in range(o):
    K.append([])
for i in range(o):
    for j in range(p):
        K[i].append(j)
        K[i][j]=0
        print("row entry:",i+1,"column entry:",j+1)
        K[i][j]=int(input())
print(K)
R=[]
for i in range(n):
    R.append([])
for i in range(n):
    for j in range(p):
        R[i].append(j)
        R[i][j]=0
for p in range(len(U)):
    for q in range(len(K[0])):
        for r in range(len(K)):
            R[p][q] += U[p][r]*K[r][q]

print("Result: ",R)
