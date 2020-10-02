#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define mp make_pair
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

// vector<int> adj[100001];
// int flag=0, x, y, f=0;
// int vis[100001]={0}, par[200001]={0}, top[500001], pop[100001]={0}, g[100001], b[100001];
// int p[100001], h[100001];

// void dfs(int n){
//     vis[n] = 1;
//     pop[n]=p[n];
//     for(auto i: adj[n]){
//         if(!vis[i]){ 
//             dfs(i);
//             pop[n] += pop[i];
//         }
//     }
// }


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
    int n, c=1, ans=0; cin>>n;
    string s; cin>>s;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    int arr[n];
    set<int> one, zer;
    arr[0]=1;
    if(s[0]=='0') zer.insert(1);
    else one.insert(1);
    int b=1;
    rep(i,1,n){
        if(s[i]!=s[i-1]){
            arr[i]=arr[i-1];
            if(s[i]=='0'){
                zer.insert(arr[i-1]);
                one.erase(arr[i-1]);
            }
            else{
                one.insert(arr[i-1]);
                zer.erase(arr[i-1]);
            }
            ans=max(ans, arr[i]);
            continue;
        }
        if(s[i]=='0'){
            if(one.size()){
                arr[i]=*one.begin();
                one.erase(*one.begin());
                zer.insert(arr[i]);
            }
            else{
                b++;
                zer.insert(b);
                arr[i]=b;
            }
        }
        else if(s[i]=='1'){
            if(zer.size()){
                arr[i]=*zer.begin();
                zer.erase(*zer.begin());
                one.insert(arr[i]);
            }
            else{
                b++;
                one.insert(b);
                arr[i]=b;
            }
        }
        ans=max(ans, arr[i]);
    }
    cout<<ans<<endl;
    rep(i,0,n) cout<<arr[i]<<" ";
    cout<<endl;
}

signed main(){
    fast
    int t=1;
    cin>>t;
    while(t--) solve();
}
