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
#define pi 3.14159265358979323
 
 
signed main(){
    fast
    int t; cin>>t;
    while(t--){
        int n, k, s, num, ans=1000000000, f=0, g=0, ans1=1000000000; cin>>n>>k;
        if(n<=k){ cout<<1<<endl; continue;}
        if(prime(n)){ cout<<n<<endl; continue;}
        repp(i,2,sqrt(n)){
            if(n%i==0){
                num=i;
                s=n/i;
                if(s<=k){f=1; ans=i; break;}
            }
        }
        if(!f){
            repp(i,2,sqrt(n)){
                if(n%i==0){
                    s=i;
                    if(s<=k){
                        ans1=n/i; g=1;
                    }
                }
            }
        }
        if(f && g) cout<<min(ans, ans1);
        else if(f && !g) cout<<ans<<endl;
        else{
            if(!g) cout<<n<<endl;
            else cout<<ans1<<endl;
        }
    }
}
