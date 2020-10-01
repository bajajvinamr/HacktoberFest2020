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

int fun(string s, int k, int n, string test){
    int ans=INF, temp=0, c=0;
    rep(i,0,k){
        if(s[i]!=test[i%3]) temp++;
    }
    ans = temp;
    rep(i,k,n){
        if(s[i]==test[i%3] && s[i-k] != test[(i-k)%3]) temp--;
        else if(s[i] != test[i%3] && s[i-k] == test[(i-k)%3]) temp++;
        ans = min(ans, temp);
    }
    return ans;
}
 

void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int ans = min(fun(s, k, n, "RGB"), min(fun(s, k, n, "GBR"), fun(s, k, n, "BRG")));
    cout<<ans<<endl;
}
 
signed main(){
    fast
    // #ifdef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t=1;
    cin>>t;
    while(t--) solve();
}
