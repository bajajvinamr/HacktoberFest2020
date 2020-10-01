#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repp(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define mod 1000000007
#define mod_in(a) bin(a, mod - 2)
#define fact(n) rep(i, 1, n+1) ft.pb((ft[i-1] * i) % mod)
#define ncr(n, r) (n >= r ? ((ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod) : 0LL)
#define pi 3.14159265358979323
#define INF 1e15
#define lb(v, a) lower_bound(v.begin(), v.end(), a)
#define ub(v, a) upper_bound(v.begin(), v.end(), a) 
#define deb(x) cerr<<#x<<" "<<x<<endl;  

 
int power(int x, int n){
    int res=1;
    while(n>0){
        if(n&1)
            res=res*x;
        x*=x;
        n>>=1;
    }
    return res;
}
 
int bin(int x, int n){
    int res=1; x%=mod;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
 
bool prime(int n){
    if(n==3)return 1;
    repp(i,2,sqrt(n)){
        if(n%i==0)return 0;
    }
    return 1;
}
 
 
// vector<int> adj[2000005];
// vector<int> pr(2000005, 1), xx[2000005];
// void sieve(int n){ 
//     for(int p=2; p<n; p++){ 
//         if(pr[p]){ 
//             for(int i=p; i<n; i += p){
//                 pr[i]=0;
//                 xx[i].pb(p);
//             }
//         } 
//     } 
// }  
// vector<int> ft(40);
 
void solve(){
    int n, k, l, r, mid, ans=0, x, ind; cin>>n>>k;
    vector<int> v;
    int dp[n+1];
    rep(i,0,n){
        cin>>x; v.pb(x);
    }
    rep(i,0,n) cin>>x;
    sort(v.begin(), v.end());
    rep(i,0,n){
        if(i && v[i]==v[i-1]){dp[i] = dp[i-1]-1; continue;}
        l = i; r = n-1;
        while(l <= r){
            mid = (l+r)/2;
            if(v[mid]-v[i]<=k){
                l = mid+1;
            }
            else r= mid-1;
        }
        dp[i] = r-i+1;
    }
    int dp1[n+1];
    dp1[n-1]=dp[n-1];
    for(int i=n-2; i>=0;i--){
        dp1[i] = max(dp1[i+1], dp[i]);
    } 
    // rep(i,0,n) cout<<dp[i]<<" ";
    // cout<<endl;
    // rep(i,0,n) cout<<dp1[i]<<" ";
    // cout<<endl;
    rep(i,0,n){
        if(dp[i] + i<=n-1){
            ans= max(ans, dp[i] + dp1[i+dp[i]]);
        }
        else ans= max(ans, dp[i]);
    }
    cout<<ans<<endl;
}
 
signed main(){
    fast
    // #ifdef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t=1;
    cin>>t;
    while(t--) solve();
