// Written by Kuji on 2020-07-01-21.19.52
#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define forr(i,a,b) for(ll i=a;i>=b;i--)
#define forit(it,x) for (auto it=(x).begin();it!=(x).end(); it++)
#define fi first
#define se second
#define sll set<ll>
#define vll vector<ll>
#define msl map<string,ll>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll x;
    cin>>x;
    vector<pair<ll,ll> > v,v1;
    pair<ll,ll>p;
    ll i;
    if(x==1)
        cout<<"1 1\n";
    else{
            p={1,x};
    for(i=1; i*i<=x; i++)
    {
        if(x%i==0)
        {
            v.pb(mp(i,x/i));
        }
    }
    for(i=0; i<v.size(); i++)
    {
        if(lcm(v[i].fi,v[i].se)==x)
        {
            if(max(v[i].fi,v[i].se)<=max(p.fi,p.se))
                p=v[i];
        }
    }
    //sort(all(v1));
    cout<<p.fi<<" "<<p.se<<"\n";
    }
}

