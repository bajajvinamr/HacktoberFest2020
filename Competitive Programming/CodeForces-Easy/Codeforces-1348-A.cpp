#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill fill_n
#define vli vector<ll>
#define pb push_back
ll po(int a,int b){
    if(b==0) return 1;
    ll ans=1;
    if(b%2==0){
      ans=po(a,b/2);
      ans=ans*ans;
    }
    else{
        ans=po(a,(b-1)/2);
        ans=ans*ans*a;
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    ll ans1=po(2,n);
	    for(int i=1;i<=n/2-1;i++){
	        ans1 += po(2,i);
	    }
	    ll ans2=0;
	    for(int i=n/2;i<=n-1;i++){
	        ans2 += po(2,i);
	    }
	    cout<<abs(ans1-ans2)<<"\n";
	    
   
	    
	   
	}
	
	return 0;
}
