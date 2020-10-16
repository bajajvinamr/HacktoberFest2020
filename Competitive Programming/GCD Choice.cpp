// To Remove an element from the array so that is GCD will be maximum
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pi pair<int,int>
#define all(v) v.begin(),v.end()
#define zeros(arr) memset(arr,0,sizeof(arr));
#define precise(num)  cout<<fixed; cout << std::setprecision(num)
#define nl cout<<"\n";
#define test int t;cin>>t;while(t--)
const int maxx  = 3*1e5 , limit = 9*1e18 , MOD=1e9+7;
string binary(int n){bitset<60>b(n) ;string p =b.to_string();return p;}
int decimal(string n) { int dec_value = 0;  int base = 1;  for (int i = n.size() - 1; i >= 0; i--) { if (n[i] == '1')
dec_value += base; base = base * 2; } return dec_value; }
bool isPrime(int n){if (n <= 1) return false; if (n <= 3) return true;if (n % 2 == 0 || n % 3 == 0) return false;
for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
int pow (int x, int n,int mod) {if (n == 0) return 1; int res = pow (x, n / 2,mod);res = (res * res) % mod;if (n % 2) res = (res * x ) % mod;return res;}
int calcInverse(int a, int n = MOD){int t = 0, newt = 1;int r = n, newr = a;  while (newr != 0) {auto quotient = r /newr;tie(t, newt) = make_tuple(newt, t- quotient * newt);
tie(r, newr) = make_tuple(newr, r - quotient * newr);}if (r > 1)throw runtime_error("a is not invertible");if (t < 0)t += n;t=t%n;    return t;}
#define boost  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n';

int32_t main(){
    boost;

    int n;
    cin>>n;
    int a[n+1];
    for(int i = 1; i <= n ; i++ )cin>>a[i];
    int dp[n+1];
    dp[0]=0;
    for(int i =1; i<= n ; i++ ){
        dp[i] = __gcd(dp[i-1] , a[i]);
    }
    int dp1[n+1];
    dp1[n]=a[n];
    for(int i = n-1; i>=1 ; i-- )
    dp1[i] = __gcd(dp1[i+1],a[i]);

    int ans = dp[n-1];
    for(int i = 1 ; i< n ;i++ ){
        ans = max(ans ,  __gcd(dp[i-1] , dp1[i+1]));
    }
    cout<<ans<<endl;


}
