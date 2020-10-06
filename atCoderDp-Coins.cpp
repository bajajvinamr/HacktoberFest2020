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

ll n;
cin>>n;
double dp[n+1][n+1];
memset(dp,0,sizeof(dp));
double ans=0;
double prob[n+1];

fr(i,1,n+1){
	cin>>prob[i];
}


dp[1][0]=1-prob[1];
fr(i,2,n+1){
	dp[i][0]=dp[i-1][0]*(1-prob[i]);
}


dp[1][1]=prob[1];
fr(i,2,n+1){
	dp[i][i]=dp[i-1][i-1]*prob[i];
}


fr(i,1,n+1){
	fr(j,1,i){
		dp[i][j]=dp[i-1][j-1]*prob[i]+dp[i-1][j]*(1-prob[i]);
	}
}

fr(i,n/2+1,n+1){
ans+=dp[n][i];
}
cout<<fixed << setprecision(10) <<ans;

}
