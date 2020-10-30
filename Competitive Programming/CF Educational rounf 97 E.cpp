#include<bits/stdc++.h>

using namespace std;

const int N = 5043;
const int MOD = 998244353;

int dp[N][N];
int pdp[N][N];
int cntLess[N];
int lastLess[N];
int a[N];
int n;

int add(int x, int y)
{
 	x += y;
 	while(x >= MOD) x -= MOD;
 	while(x < 0) x += MOD;
 	return x;
}

int sub(int x, int y)
{
 	return add(x, MOD - y);
}

int mul(int x, int y)
{
 	return (x * 1ll * y) % MOD;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	{
	 	cntLess[i] = 0;
	 	lastLess[i] = -1;
	 	for(int j = 0; j < n; j++)
	 		if(a[j] * 2 <= a[i])
	 		{
	 		 	lastLess[i] = j;
	 		 	cntLess[i]++;
	 		}
	}
	for(int i = 0; i < n; i++)
	{
	 	dp[i][1] = 1;
	 	pdp[i + 1][1] = add(pdp[i][1], dp[i][1]);
	}
	for(int k = 2; k <= n; k++)
		for(int i = 0; i < n; i++)
		{
			if(cntLess[i] + 1 >= k)
		 		dp[i][k] = add(mul(dp[i][k - 1], add(cntLess[i], sub(2, k))), pdp[lastLess[i] + 1][k - 1]);
		 	else
		 		dp[i][k] = 0;
		 	//cerr << i << " " << k << " " << dp[i][k] << endl;                                
		 	pdp[i + 1][k] = add(pdp[i][k], dp[i][k]);
		}

	cout << dp[n - 1][n] << endl;
}