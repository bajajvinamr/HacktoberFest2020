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

//  Ordered Set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
// #define os_find(k) find_by_order(k)
// #define os_order(k) order_of_key(k)
// //(*****FOR USING ORDERED SET CHANGE INT*******)


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
    int n, x, y, ans=-1; 
    cin>>n>>x>>y;
    int k= abs(x-y);
    vector<int> vv;
    rep(i,1,k+1){
        if(k%i==0){
            if(k/i <=n-1){ans=i; break;}
        }
    }
    rep(i,1,10001){
        if(i%ans==x%ans) vv.pb(i);
    }
    int a = lower_bound(vv.begin(), vv.end(), y) - vv.begin();
    if(a >=n-1){
        rep(i,a-n+1, a+1) cout<<vv[i]<<" ";
    }
    else{
        rep(i,0,n) cout<<vv[i]<<" ";
    }
    cout<<endl;
    return;
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
}
