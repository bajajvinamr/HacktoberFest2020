
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

 ll n;
 ll arr[100005][4];
 ll dp[100005][4];
//--------------------------------------------------//

ll fun(ll day,ll flag ){
	
	if(day==n) return 0;
	
	if(dp[day][flag]!=-1) return dp[day][flag];
	
	ll maxi=0;
	
	if(flag==0){
		maxi=max(maxi,arr[day][1]+fun(day+1,1));
		maxi=max(maxi,arr[day][2]+fun(day+1,2));
		maxi=max(maxi,arr[day][3]+fun(day+1,3));	
	}else if(flag==1){
        maxi=max(maxi,arr[day][2]+fun(day+1,2));
        maxi=max(maxi,arr[day][3]+fun(day+1,3));
	}else if(flag==2){
        maxi=max(maxi,arr[day][1]+fun(day+1,1));
        maxi=max(maxi,arr[day][3]+fun(day+1,3));
	}else{
        maxi=max(maxi,arr[day][1]+fun(day+1,1));
        maxi=max(maxi,arr[day][2]+fun(day+1,2));
	}
	
	return dp[day][flag]=maxi;
}
	
	


//--------------------------------------------------//


int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
  cin>>n;
  for(ll i=0;i<n;i++){
  	for(ll j=1;j<=3;j++){
  		cin>>arr[i][j];
	  }
  }
  
  memset(dp,-1,sizeof(dp));
  
  ll ans=fun(0,0);
	cout<<ans;
	
	return 0;
}
