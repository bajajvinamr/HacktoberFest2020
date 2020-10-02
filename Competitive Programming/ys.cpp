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

// bool sortt(pair<int, int> a, pair<int, int> b) {
// 	if(a.ff == b.ff) {
// 		return a.ss < b.ss;
// 	}
// 	else return a.ff > b.ff;
// }


void solve(){
    int n, k, aa=0, bb=0, ans=0, x, y, z; cin>>n>>k;
    vector<int> a,b,c;
    rep(i,0,n){
        cin>>x>>y>>z;
        if(y==1 && z!=1)a.pb(x);
        if(z==1 && y!=1)b.pb(x);
        if(y==1 && z==1)c.pb(x);
    }
    if(a.size() + c.size()<k or b.size() + c.size()<k)return void(cout<<-1<<endl);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        c.pb(a[i] + b[j]);
        i++; j++;
    }
    sort(c.begin(), c.end());
    rep(i,0,k){
        ans+=c[i];
    }
    cout<<ans<<endl;
}

signed main(){
    fast
    int t=1;
    // cin>>t;
    while(t--) solve();
}
