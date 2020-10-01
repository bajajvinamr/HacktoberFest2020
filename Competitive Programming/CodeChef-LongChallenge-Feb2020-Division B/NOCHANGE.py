t=int(input())
for _ in range(t):
    n,p=map(int,input().split())
    a=list(map(int,input().split()))
    a=sorted(a,reverse=True)
    l=[0]*n
    f=0
    for j in range((n)):
        if p%a[j]!=0:
            k=(p//a[j])+1
            l[j]=k
            f=1
            break
    if f==1:
        l.reverse()
        print("YES",*l)
    else:
        for i in range((n)):
            if p%a[i]!=0:
                k=(p//a[i])+1
                l[i]=k
                f=1
                break
            else:
                k=(p//a[i])-1
                p=p-(a[i]*k)
                l[i]=k
        if f==1:
            l.reverse()
            print("SORTED",*l)
        else:
            print("NOT SORTED")
