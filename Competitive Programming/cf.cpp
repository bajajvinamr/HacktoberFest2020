#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
bool sortt(const pair<int,string> &a,  
               const pair<int,string> &b) 
{ 
       return (a.first > b.first); 
} 
signed main()
{
    fast
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int m=n/k;
        int z=n%k;
        cout<<m*k+min(z,k/2)<<endl;
        
    }
    
}
