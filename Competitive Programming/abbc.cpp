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
#define mod 1000000007
#define pi 3.14159265358979323
 
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

void solve(){
    int n, ans=0, k; cin>>n;
    int a[n], b[n], pos[n], arr[n]={0};
    rep(i,0,n){ cin>>a[i]; pos[a[i]]=i;}
    rep(i,0,n) cin>>b[i];
    rep(i,0,n){
        if(a[i]==b[i]) arr[0]++;
    }
    rep(i,0,n){
        if(pos[b[i]]>i) k=pos[b[i]]-i;
        else k=n-i+pos[b[i]];
        arr[k]++;
    }
    rep(i,0,n) ans=max(ans, arr[i]);
    cout<<ans<<endl;
}
 
signed main()
{
    fast
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
