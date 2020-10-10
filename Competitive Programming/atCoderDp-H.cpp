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

int main(){
ll h,w;
cin>>h>>w;
char g[h][w];
ll dp[h][w];
memset(dp,0,sizeof(dp));
ll fl1=0,fl2=0,li=h,lj=w;
fr(i,0,h){
	fr(j,0,w){
		cin>>g[i][j];
//cout<<"abcd1";
		if(i==0&&g[i][j]=='#'&&fl1==0){
//cout<<"abcd2";
			fl1=1;
			lj=j;
//			cout<<j<<" ";
		}
		if(j==0&&g[i][j]=='#'&&fl2==0){
//cout<<"abcd3";
			fl2=1;
			li=i;
//			cout<<i<<" ";
		}
	}
}
fr(j,0,lj){
	dp[0][j]=1;
}
fr(i,1,li){
	dp[i][0]=1;
}

fr(i,1,h){
	fr(j,1,w){
		if(g[i][j]=='#'){
			dp[i][j]=0;
		}else{
			dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-1]%mod))%mod;
		}
	}
}


//cout<<"abcd";
//fr(i,0,h){
//	fr(j,0,w){
//cout<<dp[i][j]<<" ";
//}
//cout<<endl;
//}
cout<<dp[h-1][w-1]%mod;
}
