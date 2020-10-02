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
        int n;
        cin>>n;
        if(n==2){
            cout<<2<<endl;
        }
        else if(n%2){
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        
    }
}
