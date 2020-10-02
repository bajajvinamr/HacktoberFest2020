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
#define mod 1000000009
#define mod_in(a) bin(a, mod - 2)
#define fact(n) rep(i, 1, n+1) ft.pb((ft[i-1]*i)%mod)
#define ncr(n, r) (n>=r?((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod):0LL)
#define pi 3.14159265358979323
#define INF 1e15
#define lb(v, a) lower_bound(v.begin(), v.end(), a)
#define ub(v, a) upper_bound(v.begin(), v.end(), a)

int po(int x, int n){
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

// vector<int> adj[500001];
// int flag=0;
// int vis[500001]={0}, par[200001]={0}, top[500001];

// void dfs(int n, int p){
//     vis[n] = 1;
//     for(auto i: adj[n]){
//         if(top[i] == top[n]) flag=1;
//         if(!vis[i]) dfs(i, n);
//     }
// 

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
    int n, ans=0, x=-1; cin>>n;
    string a, b; cin>>a>>b;
    vector<int> v;
    for(int i=n-1; i>=0;i--){
        if(a[i] == b[i]){
            continue;
        }
        else{
                v.pb(i+1);
                v.pb(1);
                v.pb(i+1);
        }
    }
    cout<<v.size()<<" ";
    rep(i,0,v.size()) cout<<v[i]<<" ";
    cout<<endl;
}

signed main(){
    fast
    // ft.pb(1);
    // fact(1000000);
    int t=1;
    cin>>t;
    while(t--) solve();
}
