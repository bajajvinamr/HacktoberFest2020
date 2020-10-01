#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define mod 1000000007
 
int power(int x,int n){
    int res=1;
    while(n>0){
        if(n&1)
            res=res*x;
        x*=x;
        n>>=1;
    }
    return res;
}
 
int bin(int x,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
 
signed main()
{
    fast
    string t, p; cin>>t>>p;
    int ans=0;
    int arr[t.size()];
    rep(i,0,t.size())cin>>arr[i];
    int l=0, r=t.size(), mid=(l+r)/2;
    while(l<=r){
        bool chk[200006]={0};
        mid=(l+r)/2;
        rep(i,0,mid){
            chk[arr[i]-1]=1;
        }
        int i=0, j=0;
        while(i<p.size() && j<t.size()){
            while(chk[j] && j<t.size())j++;
            if(j<t.size() && p[i]==t[j])i++;
            j++;
        }
        if(i==p.size()){ans=mid; l=mid+1;}
        else r=mid-1;
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
