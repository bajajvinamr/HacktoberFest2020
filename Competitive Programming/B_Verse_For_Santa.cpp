#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define mll map<long long,long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000

 
using namespace std;
 
ll n,k;
vector<ll>v;

 
void Input() {
    cin>>n>>k;
    v.resize(n);

    cin>>v[0];
  
    for(ll i=1;i<n;i++){
        cin>>v[i];
      
    }
}

 
void Solve() {
    ll sum=0,mx=-1,pos=-1;

   for(ll i=0;i<n;i++){
       sum+=v[i];
       if(v[i]>mx){
           mx=v[i];
           pos=i;
       }
       if(sum>k) break;

   }

   if(sum<=k) cout<<0<<endl;

   else cout<<pos+1<<endl;
  
  
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

 
	ll T = 1;
	cin >> T;
	while (T--) {
        v.clear();
    
		Input();
		Solve();
	}
	return 0;
}