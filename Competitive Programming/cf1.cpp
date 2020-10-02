#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define mod 1000000007
 
bool sorttt(const pair<int, pair<char, int> > &a, 
              const pair<int, pair<char, int> > &b) 
{ 
    return (a.first > b.first); 
}
 
int pow_(int x,int n){
    int res=1;
    while(n>0){
        if(n&1)
            res=res*x;
        x*=x;
        n>>=1;
    }
    return res;
}
 
int bin(int x,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}

vector<int> adj[200001];
bool vis[200001]={0};
int ans=0;

void dfs(int x){
    vis[x]=1;
    ans++;
    for(auto i : adj[x]){
        if(!vis[i])dfs(i);
    }
}

signed main()
{
    fast
    int n, k, x, y, t, res=0; cin>>n>>k;
    vector<int> v;
    set<int> s;
    rep(i,0,n-1){
        cin>>x>>y>>t;
        if(t!=1){adj[x].pb(y); adj[y].pb(x); s.insert(x); s.insert(y);}
    }
    for(auto i : s){
        if(!vis[i])dfs(i);
        v.pb(ans);
        // cout<<ans<<endl;
        ans=0;
    }
    rep(i,0,v.size()){
        res=(res+bin(v[i],k))%mod;
    }
    res=(res+n-s.size())%mod;
    cout<<(bin(n, k)-res+ mod)%mod;
}
