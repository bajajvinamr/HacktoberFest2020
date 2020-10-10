#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define lo(i, s, n)     for (ll i = s; i <= n; i++)
#define sca(n)          scanf("%lld", &n)
#define pri(n)          printf("%lld", n)
#define pb              push_back
#define mp              make_pair
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case "<<tc<<": "
#define nl              cout<<"\n";
#define pnl             printf("\n");
#define pi              acos(-1)
#define mod             1000000007
#define inf             999999999999999999
			
 
 
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
 
    ll t;
    cin>>t;
    while(t--){
        ll ca, cb, na, nb, waa, wbb;
        cin>>ca>>cb>>na>>nb>>waa>>wbb;
        ll wa=min(waa, wbb);
        ll wb=max(waa, wbb);
        if(wa!=waa) swap(na, nb);
        ll ta= min(ca/wa+cb/wa, na);
        ll mx=ta;
        for(ll i=0; i<=ta; i++){
            ll sum=ta;
            ll j = ta - i;
            if(ca>=i*wa && cb>=j*wa){
                ll caa=ca;
                ll cbb=cb;
                ll nbb=nb;
                caa-=i*wa;
                cbb-=j*wa;
                ll b = min(nbb, caa/wb);
                nbb-=b;
                sum+=b;
                b = min(nbb, cbb/wb);
                nbb-=b;
                sum+=b;
                mx=max(sum, mx);
            }
        }
        cout<<mx; 
        nl
    }
    return 0;
}