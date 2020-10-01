n = int(input())
a = list(map(int,input().split()))
d = [0 for i in range(3)]
dp = [[[0 for i in range(n+1)] for j in range(n+1)] for k in range(n+1)] 
for i in a:
    d[i-1] +=1
for k in range(n+1):
    for j in range(n+1):
        for i in range(n+1):
            if i+j+k==0 or i+j+k>n:
                continue
            ans = n/(i+j+k)
            x = i/(i+j+k)
            if x:
                ans += x*dp[k][j][i-1]
            x = j/(i+j+k)
            if x:
                ans += x*dp[k][j-1][i+1]
            x = k/(i+j+k)
            if x:
                ans += x*dp[k-1][j+1][i]
            dp[k][j][i] = ans
print(dp[d[2]][d[1]][d[0]])
