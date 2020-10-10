#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill fill_n
#define vli vector<ll>
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	map<string,ll> m,t;
	string s[n];
	ll sc[n];
	for(int i=0;i<n;i++){
	   cin>>s[i];
	   cin>>sc[i];
	   m[s[i]]+=sc[i];
	}

	ll ans = -1e12;
	for(auto i:m){
	    if(i.second > ans){
	        ans=i.second;
	    }
	}
	vector<string> v;
	for(auto i:m){
	    if(i.second==ans){
	        v.pb(i.first);
	    }
	}
	for(int i=0;i<n;i++){
	    if(t[s[i]]>=ans && find(v.begin(),v.end(),s[i])!=v.end()){
	        cout<<s[i]<<"\n";
	        break;
	    }
	    t[s[i]] += sc[i];
	    if(t[s[i]]>=ans && find(v.begin(),v.end(),s[i])!=v.end()){
	        cout<<s[i]<<"\n";
	        break;
	    }
	}
	
	return 0;
}
