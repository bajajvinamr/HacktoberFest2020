#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin>>t; while(t--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define f0(i,n) for( ll i = 0; i < ( n ); i ++)
#define f1(i,n) for(i = 1; i <= ( n ); i ++)
#define f(i,m,n) for(auto i = ( m ); i <= ( n ); i ++)
#define nl cout<<"\n"
#define  mod 1000000007
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(), v.rend()
#define SZ(x) ((ll)x.size())
#define mem(a, b) memset(a, b, sizeof(a));
#define make_graph(k) int x,y; f0(i,k){cin>>x>>y; adj[x].pb(y); /*adj[y].pb(x);*/}
#define dekh cout<<"dekh"

#define o_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setpll tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
typedef vector<ll> vl;




/*ll Pow(ll a, ll b, ll m){
    if(b==0)return 1;
    if(b%2==0){
        ll x = a*a;
        x%=m;
        return Pow(x,b/2,m);
    }
    return (a*Pow(a,b-1,m))%m;
}
*/
/*vector<ll>adj[200005];
 ll vis[200005]={0};
 ll depth[200005]={0};*/

//ll p;ll arr[200005];
/*
void dfs(ll x)
{

    vis[x]=1;

    for(auto child : adj[x])
    {   if(!vis[child])
         {
             dfs(child);
         }
         depth[x]= max(depth[x],depth[child]+1);

    }

}

*/
ll n;ll flag=0;ll arr[17];
ll solve( ll ind ,ll sum)
{
   // cout<<ind<<" "<<sum;nl;
      if(ind==n && sum==0){flag=1; return 0;}
      if(ind>=n)return 0;

    ll ans1 = solve(ind+1,(sum+arr[ind]%360)%360);
    ll ans2 = (solve(ind+1,(sum-arr[ind]+360)%360));

}

int main()
{
   fast
   cin>>n;
   f0(i,n)cin>>arr[i];
   ll ans=  solve(0 , 0);
   if(flag){cout<<"YES";}
   else cout<<"NO";
}
