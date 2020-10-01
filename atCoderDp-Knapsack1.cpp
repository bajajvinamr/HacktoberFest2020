
#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define ull unsigned long long int
#define po2(z) 1<<(ll)z
#define fr(i,x,n) for(ll i=(ll)(x);i<(ll)(n);++i)
#define rf(i,x,n) for(ll i=(ll)(x);i>=(ll)(n);--i)
#define modinv(x) powah(x,mod-2)
#define ncr(n,r) (((fact[n]*modinv(fact[n-r]))%mod*modinv(fact[r]))%mod)
#define factorial fact.pb(1);sidha(i,1,MAX)fact.pb((fact[i-1]*i)%mod)
#define tej ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod (ll)1000000007
#define MAX 100005
#define Vii  vector<ll>
#define pb  push_back
#define pii pair<ll,ll>
#define ff  first
#define ss second
#define vpii vector<pii >
#define endl '\n'

ll n,W;
ll wt[110];
ll val[110];
ll dp[110][100005];
//--------------------------------------------------//
ll KS(ll n,ll W){
	if(n==0||W==0){
		return 0;
	}
	
	if(dp[n][W]!=-1) return dp[n][W];
	
	if(wt[n]>W){
		return dp[n-1][W] = KS(n-1,W);
	}
	else{
		return dp[n][W]=max(val[n]+KS(n-1,W-wt[n]),KS(n-1,W));
	}

}

//--------------------------------------------------//


int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	
	cin>>n>>W;
	memset(wt,0,sizeof(wt));
	memset(val,0,sizeof(val));
	memset(dp,-1,sizeof(dp));
	for(ll i=1;i<=n;i++){
		cin>>wt[i]>>val[i];
	}
	cout<<KS(n,W);

}
