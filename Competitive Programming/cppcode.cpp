#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define mod 998244353
#define pi 3.14159265358979323
#define INF 1e15

void solve(){
    int k, upto=1, i=0; cin>>k;
    int dp[15];
    string res="codeforces";
    rep(i,0,15) dp[i]=1;
    while(upto<k){
        i=(i+1)%10;
    	dp[i]++;
    	upto=1;
    	rep(i,0,10){
    		upto*=dp[i];
    	}
    }
    rep(i,0,10) rep(j,0,dp[i]) cout<<res[i];
    cout<<endl;
}

signed main()
{
    fast
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
