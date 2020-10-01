
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
  ll n,x,y,mini=1000000005;
  cin>>n;
 ll m=n;
  unordered_map<ll,ll>umap1;
  unordered_map<ll,ll>umap2;
 	vector<ll>c;
  umap1.clear();
  umap2.clear();
  c.clear();
  while(m--){
  	cin>>x;
  	mini=min(mini,x);
  	umap1[x]+=1;
  }
  m=n;
  while(m--){
  	cin>>x;
  	mini=min(mini,x);
  	if(umap1.find(x)==umap1.end()){
  		umap2[x]++;
  	
	  }else{
	  	if(umap1[x]>0){
	  		umap1[x]--;
		  }
		  if(umap1[x]==0){
		  	umap1.erase(x);
		  }
	  	
	  }
  }
  
vector<ll>a;
vector<ll>b;


ll flag=0,cost=0;
   for(auto it=umap1.begin();it!=umap1.end();it++){
  	if(it->second%2){
  		flag=1;
	  }
	  else{
	  	ll f=it->second;
	  	a.insert(a.end(),f,it->first);
	  }
  }
   for(auto it=umap2.begin();it!=umap2.end();it++){
  if(it->second%2){
  		flag=1;
	  }
	  else{
	  ll f=it->second;
	  	b.insert(b.end(),f,it->first);
	  }
  }
 if(a.size()!=b.size()) 
 {
 	flag=1;
 }else{
 	sort(a.begin(),a.end());
 	sort(b.begin(),b.end(),greater<ll>());
 	for(ll i=0;i<a.size();i++){
 		cost+=min(min(a[i],b[i]),2*mini);
	 }
 }
  
  if(flag){
  	cout<<-1<<endl;
  }else{
  	cout<<cost/2<<endl;
  }
}

}
