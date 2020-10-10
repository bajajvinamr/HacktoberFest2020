#include <bits/stdc++.h>
#define int long long
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i<=b; i++)
#define repp(i, a, b) for(int i=b-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define bn begin()
#define en end()
#define SZ(x) ((int)(x).size())
#define db double
#define mi map<int, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
#define mod 1000000007
#define pi 3.141592653589
#define INF 1000000000000
using namespace std;

int power(int x, int y) ;
int gcd(int a, int b) ;


signed main() {
    quickie   
    int n, k ;
    cin >> n >> k ;
    vi v, v1, v2 ;
    int aa = 0 , bb = 0 ;
    rep(i, 0, n) {
        int t, a, b ;
        cin >> t >> a >> b ;
        if(a == 1 && b == 1) {
            v.pb(t) ;
            aa++ ;
            bb++ ;
        }
        else if(a == 1) {
            v1.pb(t) ;
            aa++ ;
        }
        else if(b == 1) {
            v2.pb(t) ;
            bb++ ;
        }
    }
    if(aa < k || bb < k) {
        cout << "-1\n" ;
        return 0 ;
    }
    sort(v1.begin(), v1.end()) ;
    sort(v2.begin(), v2.end()) ;
    rep(i, 0, min(v1.size(), v2.size())) {
        v.pb(v1[i]+v2[i]) ;
    }
    int s = 0 ;
    sort(v.begin(), v.end()) ;
    rep(i, 0, k) {
        s += v[i] ;
    }
    cout << s << "\n" ;
}

int power(int x, int y) {
    int res = 1; x %= mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
