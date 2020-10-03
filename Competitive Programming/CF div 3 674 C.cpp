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

int dfs(int n){
    ti++;
    in[n] = ti;
    int te = t[n];
    for(auto i: adj[n]){
        te += dfs(i);
    }
    ti++;
    out[n] = ti;
    // cout<<te<<" "<<n<<" "<<sum<<endl;
    if(te==sum){ v.pb(n); te=0;}
    return te;
}

void solve(){
    int n, x, y, root; cin>>n;
    rep(i,0,n){
        cin>>x>>y;
        if(x){
            adj[x].pb(i+1);
        }
        else root = i+1;
        t[i+1] = y;
        sum += y;
    }
    if(sum % 3) return void(cout<<-1<<endl);
    sum/=3;
    dfs(root);
    // cout<<v.size()<<endl;
    if(v.size() < 3) {cout<<-1<<endl; return;}
    cout<<v[0]<<" "<<v[1]<<endl;
}

signed main(){
    fast
    int t=1;
    // cin>>t;
    while(t--) solve();
}
