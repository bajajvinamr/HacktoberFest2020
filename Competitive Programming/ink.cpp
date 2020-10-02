#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
signed main()
{
    fast
    int t;
    cin>>t;
    while(t--){
        int n,j=100000,k=100000,l=-100000,m=-100000;
        cin>>n;
        while(n--){
            int x,y,a,b,c,d;
            cin>>x>>y>>a>>b>>c>>d;
            if(a==0){
                l=max(l,x);
            }
            if(b==0){
                k=min(k,y);
            }
            if(c==0){
                j=min(j,x);
            }
            if(d==0){
                m=max(m,y);
            }
        }
        // cout<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
        if(j<l or k<m){
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<" "<<l<<" "<<m<<endl;;
        }
        
    }
}
