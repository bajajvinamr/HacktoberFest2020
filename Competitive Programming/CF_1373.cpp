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


int maxsum (int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

signed main() {
    quickie 
    test
    while(t--) {
        int n ;
        cin >> n ;
        int a[n] ;
        int s = 0 ;
        rep(i, 0, n) {
            cin >> a[i] ;
            if(i%2 == 0) s+=a[i] ;
        }
        vi v1, v2 ;
        rep(i, 0, n) {
            if(i+1 < n) {
            v1.pb(a[i+1]-a[i]) ;
            i++ ;
            }
        }
        rep(i, 1, n) {
            if(i+1 < n) {
            v2.pb(a[i]-a[i+1]) ;
            i++ ;
            }
        }
        int xx = v1.size(), yy = v2.size() ;
        int b[xx], c[yy] ;
        rep(i, 0, xx) {
            b[i] = v1[i] ;
        }
        rep(i, 0, yy) {
            c[i] = v2[i] ;
        }
        int m1 = maxsum(b, xx), m2 = maxsum(c, yy) ;
        int mm = max(m1, m2) ;
        if(mm > 0) cout << s + mm << "\n" ;
        else cout << s << "\n" ;
    }
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
