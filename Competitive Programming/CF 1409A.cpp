#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long 
#define testcase long long t; cin>>t;

int main()
{
	testcase;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(b>a){
			ll d = b-a;
			ll c = d/10;
			ll r = d%10;
			if(r!=0)
			cout<<c+1<<endl;
			else cout<<c<<endl;
		}
		else if (a==b) cout<<0<<endl;
		else{
			ll d= a-b;
			ll c = d/10;
			ll r = d%10;
			if(r!=0)
			cout<<c+1<<endl;
			else cout<<c<<endl;
		}
	
		
	}
	return 0;
}
