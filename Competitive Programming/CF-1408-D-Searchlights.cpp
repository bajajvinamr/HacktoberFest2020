#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define rep(i,k,n) for(int i = k; i < n; i++)  
#define per(i,k,n) for(int i = k; i >= n; i--)  
#define repp(i,a,n,k) for(typeof(a) i=a;i!=n;i+=k)

#define int long long
#define all(a) a.begin(),a.end()       

#define pb push_back
typedef long long ll; 
typedef pair<int, int> ii;
typedef pair<int,ii > iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<char> vchar;

#define fill(a,b) memset(a, b, sizeof(a))
#define setbits(x) __builtin_popcountll(x)

#define ff first
#define ss second

#define lb lower_bound
#define ub upper_bound
#define me max_element

#define INF 1000000000
//#define mod 998244353
#define mod 1000000007
#define endl "\n"


  


int modPow(int a, int b);
int modInv(int a);     




void solve(){
    
    int n,m;
    cin >> n >> m;
    ii a[n], b[m];
    rep(i,0,n)cin >> a[i].ff >> a[i].ss;
    rep(i,0,m)cin >> b[i].ff >> b[i].ss;

    int c[n][m], d[n][m];


    vii aa, bb;
    rep(i,0,n){
        ii temp={0,0};
        rep(j,0,m){
            c[i][j] = max(0ll,b[j].ff - a[i].ff +1);
            d[i][j] = max(0ll,b[j].ss - a[i].ss + 1);
        }
    }

    
    vii g,h;
    rep(i,0,n){
        rep(j,0,m){
            ii temp;
            temp.ff = (c[i][j]);
            temp.ss = (d[i][j]);
            g.pb(temp);
        }
    }
    
    sort(all(g));
    int x[g.size()+1]={0};

    int maxi=0;
    per(i,g.size()-1,0){
        maxi = max(maxi, g[i].ss);
        x[i]=maxi;
    }

    int ans = x[0];
    rep(i,0,g.size()){
        int tmp = g[i].ff + + x[i+1];
        ans = min(ans,tmp );
    
    }

    cout << ans <<endl;




}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

int modPow(int a, int b){
    if(b==0)return 1;
    if(b%2==0){
        int x = a*a;
        x%=mod;
        return modPow(x,b/2);
    }
    return (a*modPow(a,b-1))%mod;
}


int modInv(int a){
    return modPow(a,mod-2);
}



