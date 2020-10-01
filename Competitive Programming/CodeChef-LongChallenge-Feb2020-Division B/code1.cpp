#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
// #define mp make_pair
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repp(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define mod 1000000007
#define mod_in(a) bin(a, mod - 2)
#define ncr(n, r) (n >= r ? ((ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod) : (int)0)
#define pi 3.14159265358979323
#define INF 1e15
#define lb(v, a) lower_bound(v.begin(), v.end(), a)
#define ub(v, a) upper_bound(v.begin(), v.end(), a)
 
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
    return res%mod;
}
// vector<int> ft;
 
// int ncr(int n, int r){
//     if(n>=r){
//         return (ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod;
//     }
//     else return 0;
// }        
 
bool prime(int n){
    if(n==3)return 1;
    repp(i,2,sqrt(n)){
        if(n%i==0)return 0;
    }
    return 1;
}
 
// vector<int> pr(500005, 1), xx[500005];
// void sieve(int n){ 
//     pr[1] = 0;
//     for(int p=2; p<=n; p++){ 
//         if(pr[p]){ 
//             for(int i=p; i<=n; i += p){
//                 pr[i]=0;
//                 xx[i].pb(p);
//             }
//         } 
//     } 
// } 
vector<int> adj[200001];
int vis[200001];
 
void update(string s, int x[], int ind){
    for(auto i: s){
        if(x[i - 'a' + 1] && find(adj[ind].begin(), adj[ind].end(), x[i - 'a' + 1])==adj[ind].end()){
            adj[ind].pb(x[i - 'a' + 1]);
            adj[x[i - 'a' + 1]].pb(ind);
        }
        else if(x[i - 'a' + 1]==0){
            x[i - 'a' + 1] = ind;
        }
    }
}
void dfs(int n){
    vis[n] = 1;
    for(auto i : adj[n]) if(!vis[i]) dfs(i);
}
 
void solve(){
    int n, ans=0; cin>>n;
    string s;
    int x[150]={0};
    rep(i,0,n){
        cin>>s;
        update(s, x, i + 1);
    }
    rep(i,1,n+1){
        if(!vis[i]){ dfs(i); ans ++;}
    }
    cout<<ans<<endl;
}
 
signed main(){
    fast
    // ft.pb(1);    
    // rep(i,1,2000005) ft.pb((ft[i-1]*i)%mod);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
