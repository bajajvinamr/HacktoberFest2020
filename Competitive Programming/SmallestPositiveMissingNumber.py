'''
Question:
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.
'''
for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    d=[]
    for i in range(n):
        if l[i]>0:
            d.append(l[i])
    d=list(set(d))
    d.sort()
    for i in range(len(d)):
        if d[i]!=(i+1):
            print(i+1)
            break
    else:
        print(len(d)+1)
