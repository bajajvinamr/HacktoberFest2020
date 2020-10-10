#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill fill_n
#define pf push_front
#define pb push_back
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define comp(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define infile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvli;
const int M = 1e9+7;
const int N = 2e5;
ll po(int,int);


void solve(){
    int n;cin>>n;
    ll a[n],b[n];
    ll ma=1e14,mb=1e14;
    FOR(i,0,n){
        cin>>a[i];
        ma=min(ma,a[i]);
    }
    FOR(i,0,n){
        cin>>b[i];
        mb = min(mb,b[i]);
    }
    ll ans=0;
    FOR(i,0,n){
        if(a[i]==ma || b[i]==mb){
            ans += (a[i]-ma + b[i]-mb);
        }
        else ans += max(a[i]-ma,b[i]-mb);
    }
    cout<<ans<<"\n";
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t=1;
    cin>>t;
    FOR(i,1,t+1){
        //cout<<"Case #"<<i<<": "; 
        solve();
    }
    
	return 0;
	
	
}


ll po(int a,int b){
    if(b==0) return 1;
    ll ans=1;
    if(b%2==0){
        ans = po(a,b/2)%M;
        ans=(ans%M * ans%M)%M;
    }
    else{
        ans = po(a,(b-1)/2)%M;
        ans = (ans%M * ans%M * a)%M;
    }
    return ans%M;
}
