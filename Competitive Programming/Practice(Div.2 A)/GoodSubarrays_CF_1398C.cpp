#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i<=b; i++)
#define repp(i, a, b) for(int i=b-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define db double
#define mi map<int, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
#define pii pair<int, int>
#define mod 1000000007
#define pi 3.141592653589
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod) ;

signed main() {
    quickie
    test
    while(t--) {
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;
        int a[n] ;
        rep(i, 0, n) {
            a[i] = s[i]-'0' ;
            a[i]-- ;
        }
        unordered_map<int, int> m ;
        int res = 0, curr = 0 ;
        rep(i, 0, n) {
            curr += a[i] ;
            if(curr == 0) res++ ;
            if(m.find(curr) != m.end()) res += (m[curr]) ;
            m[curr]++ ;
        }
        cout << res << "\n" ;
    }
}

