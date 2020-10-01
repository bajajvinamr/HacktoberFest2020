#include<bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

/* // Ordered Set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
*/

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
#define f0(i,a,b) for(long long i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)

int binExp(int x,int n)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
// int fact[300001];
// int modInv(int i) {return binExp(i,mod-2);}
// int ncr(int n,int r) {return (fact[n]*modInv(fact[r]))%mod*modInv(fact[n-r])%mod;}

vi adj[100001];
bool vis[100001];
int white[100001];
int black[100001];

void dfs(int v)
{
    vis[v] = 1;
    int wh = 1;
    int bl = 1;
    for(auto x : adj[v])
    {
        if(!vis[x])
        {
            dfs(x);
            wh = (wh*((white[x]+black[x])%mod))%mod;
            bl = (bl*white[x])%mod;
        }
    }
    white[v] = wh;
    black[v] = bl;
}

signed main()
{
    fast

    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif

    int n;
    cin>>n;


    f1(i,1,n) vis[i] = 0;
    make_graph(n-1);

    dfs(1);
    cout<<(white[1]+black[1])%mod;
}
