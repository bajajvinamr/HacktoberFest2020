t=int(input())
for _ in range(t):
    ok,notok=map(int,input().split())
    a=list(map(int,input().split()))
    a=sorted(a,reverse=True)
    l=[0]*ok
    flag=0
    for i in range((ok)):
        if notok%a[i]!=0:
            k=(notok//a[i])+1
            l[i]=k
            flag=1
            break
    if flag==1:
        l.reverse()
        print("YES",*l)
    else:
        for i in range((ok)):
            if notok%a[i]!=0:
                k=(notok//a[i])+1
                l[i]=k
                flag=1
                break
            else:
                k=(notok//a[i])-1
                notok=notok-(a[i]*k)
                l[i]=k
        if flag==1:
            l.reverse()
            print("YES",*l)
        else:
            print("NO")
