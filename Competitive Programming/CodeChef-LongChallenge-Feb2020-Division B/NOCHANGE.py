t=int(input())
for _ in range(t):
    n,p=map(int,input().split())
    a=list(map(int,input().split()))
    a=sorted(a,reverse=True)
    l=[0]*n
    flag=0
    for i in range((n)):
        if p%a[i]!=0:
            k=(p//a[i])+1
            l[i]=k
            flag=1
            break
    if flag==1:
        l.reverse()
        print("YES",*l)
    else:
        for i in range((n)):
            if p%a[i]!=0:
                k=(p//a[i])+1
                l[i]=k
                flag=1
                break
            else:
                k=(p//a[i])-1
                p=p-(a[i]*k)
                l[i]=k
        if flag==1:
            l.reverse()
            print("YES",*l)
        else:
            print("NO")