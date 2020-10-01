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

int segbase[200001];
int a[200001];
int h[200001];
int segtree[524300];

int combine(int a, int b) {return max(a,b);}

void update(int node, int cl, int cr, int idx, int val)
{
    if(idx < cl || cr < idx)
    {
        return;
    }

    if(cl == cr)
    {
        segbase[idx] = val;
        segtree[node] = val;
        return;
    }
    int cm = (cl+cr)/2;

    if(cl <= idx && idx <= cm)
    {
        update(2*node, cl, cm, idx, val);
    }
    else
    {
        update(2*node+1, cm+1, cr, idx, val);
    }

    segtree[node] = combine(segtree[2*node], segtree[2*node+1]);
}

int query(int node, int cl, int cr, int l, int r)
{
    if(cr < l || r < cl) return 0;
    if(l <= cl && cr <= r) return segtree[node];

    int cm = (cl+cr)/2;
    int one = query(2*node, cl, cm, l, r);
    int two = query(2*node+1, cm+1, cr, l, r);

    return combine(one, two);
}

signed main()
{
    // fast

    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif

    int n;
    cin>>n;

    f1(i,0,524299) segtree[i] = 0;
    
    f0(i,0,n) cin>>h[i];

    f0(i,0,n) cin>>a[i];

    int ans = 0;
    f0(i,0,n)
    {
        int z = query(1,0,n-1,0,h[i]-1);
        update(1,0,n-1,h[i],z+a[i]);
        ans = max(ans, z+a[i]);
        // cout<<i<<' '<<z<<' '<<a[i]<<'\n';
    }
    cout<<ans;
}
