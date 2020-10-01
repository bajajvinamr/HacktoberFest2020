#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
const int mod=1000000007;
const int INF=1e18;
int a[105],b[105],c[105],d[105];
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		f(i,1,n+1)
			cin>>a[i];
		f(i,1,n+1)
			cin>>b[i];
		f(i,1,n+1)
			cin>>c[i];
		f(i,1,n) {
			if(a[i]!=d[i-1])
				d[i]=a[i];
			else if(b[i]!=d[i-1])
				d[i]=b[i];
			else if(c[i]!=d[i-1])
				d[i]=c[i];
		}
		if(a[n]!=d[n-1] && a[n]!=d[1])
			d[n]=a[n];
		else if(b[n]!=d[n-1] && b[n]!=d[1])
			d[n]=b[n];
		else if(c[n]!=d[n-1] && c[n]!=d[1])
			d[n]=c[n];
		f(i,1,n+1)
			cout<<d[i]<<" ";
		cout<<'\n';
	}
	
	return 0;
}
