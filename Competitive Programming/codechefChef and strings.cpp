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
#define TC ll test;cin>>test;while(test--)
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


//--------------------------------------------------//



//--------------------------------------------------//


int main(){
  tej;
  TC{
  ll n;
  cin>>n;
  ll arr[n];
  ll ans=0;
  cin>>arr[0];
  for(ll i=1;i<n;i++){
  	cin>>arr[i];
  	ans+=abs(arr[i]-arr[i-1])-1;
  }
  cout<<ans<<endl;
  }

}
