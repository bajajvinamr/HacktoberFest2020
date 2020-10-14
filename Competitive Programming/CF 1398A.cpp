#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long 
#define testcase long long t; cin>>t;

int main()
{
	testcase;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for (ll i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		if (a[0]+a[1]>a[n-1]) cout<<-1<<endl;
		else cout<<1<<" "<<2<<" "<<n<<endl;
		}
		return 0;
		
	}

