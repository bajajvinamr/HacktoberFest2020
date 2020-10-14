def RulingPair(arr, n): 
    # code here
    d=dict()
    
    
    for i in arr:
        s=str(i)
        x=0
        for j in range(len(s)):
            x=x+int(s[j])
        d[x]=[i] if x not in d else d[x].append(i)
    
    maxi=-1
    l=[]
    for i in d:
        if len(d[i])>1:
            x1=d[i].index(max(d[i]))
            x=d[i][x1]
            d[i]=d[i][:x1]+d[i][x1+1:]
            x=x+max(d[i])
            maxi=max(maxi,x)
    return maxi
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(RulingPair(arr,n))
