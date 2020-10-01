#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
// #define mp make_pair
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
#define deb(x) cerr<<#x<<" "<<x<<endl;  


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
 

void solve(){
    int n, l, r, mid; cin>>n;
    vector<int> v(n), pre(n), suf(n);
    rep(i,0,n) cin>>v[i];
    pre[0] = v[0];
    rep(i,1,n) pre[i] = pre[i-1] + v[i];
    if(pre[n-1]%2) return void(cout<<"NO\n");
    rep(i,0,n-1) if(pre[i]==pre[n-1]/2){
        cout<<"YES\n";
        return;
    }
    suf[n-1] = v[n-1];
    for(int i=n-2; i>=0;i--) suf[i]= suf[i+1] + v[i];
    rep(i,0,n-1){
        l = i; r=n;
        while(l<=r){
            mid = (l+r)/2;
            if(pre[mid] > pre[n-1]/2 + v[i]) r = mid-1;
            else if(pre[mid] < pre[n-1]/2 + v[i]) l = mid+1;
            else{
                cout<<"YES\n"; return;
            }
        }
    }
    for(int i=n-1; i>=1;i--){
        l = 0; r= i;
        while(l<=r){
            mid=(l+r)/2;
            if(suf[mid] > pre[n-1]/2 + v[i]) l = mid + 1;
            else if(suf[mid] < pre[n-1]/2 + v[i]) r= mid- 1;
            else{
                cout<<"YES\n"; return;
            }
        }
    }
    cout<<"NO\n";
}
 
signed main(){
    fast
    // #ifdef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t=1;
    // cin>>t;
    while(t--) solve();
}
