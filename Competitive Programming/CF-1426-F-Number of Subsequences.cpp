#include<bits/stdc++.h>
 
#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) int((v).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
#define deb(x) cout << #x << "=" << x << endl
#define PI 3.1415926535897932384626
#define endl '\n'
 
using namespace std;
 
typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;
 
 
void solve() {
	int n;
	cin >> n;
 
	vll dp(4, 0);
	dp[0] = 1;
 
	string s;
	cin >> s;
 
	for(auto c: s) {
		vll ndp = dp;
		if(c == '?') {
			rep(i, 0, 4) {
				ndp[i] = ((dp[i] * 3) % mod + (i != 0 ? dp[i - 1] : 0)) % mod;
			}
		}
		else ndp[c - 'a' + 1] = (dp[c - 'a' + 1] + dp[c - 'a']) % mod;
		dp = ndp;
	}
	cout << dp[3] << endl;
 
}
 
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
 
int t = 1;
while(t--) {
solve();
}
}
