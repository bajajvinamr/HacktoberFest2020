#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fill fill_n
#define pf push_front
#define pb push_back
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<pair<int,int>> vpi;

const int M = 1e9+7;
const int N = 2e5;

typedef struct queries{
    int c,id;
    ll x;
}Q;

vector<Q> v(N+5);

void solve(){
    int n;cin>>n;
    ll a[n+1];
    FOR(i,1,n+1){
        cin>>a[i];
    }
    int q;cin>>q;
    FOR(i,0,q){
        cin>>v[i].c;
        if(v[i].c == 1){
            cin>>v[i].id>>v[i].x;
        }
        else{
            v[i].id = -1;
            cin>>v[i].x;
        }
    }
    // FOR(i,0,q){
    //     cout<<v[i].c<<" "<<v[i].id<<" "<<v[i].x<<"\n";
    // }
    bool vis[n+5]={0};
    ll mx = -1;
    ROF(i,q-1,0){
        if(v[i].c == 2){
            mx = max(mx,v[i].x); 
        }
        else{
            if(!vis[v[i].id]){
            a[v[i].id] = max(mx,v[i].x);
            vis[v[i].id] = 1;
            }
        }
    }
    
    FOR(i,1,n+1){
        if(!vis[i]){
            a[i] =  max(a[i],mx); 
        }
    }
    
    FOR(i,1,n+1){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
    

}




int main() {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
    
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin);  
   freopen("output.txt", "w", stdout); 
   #endif 

    int t=1;
    //cin>>t;
    FOR(i,1,t+1){
        //cout<<"Case #"<<i<<": "; 
        solve();
        
    }
    
    return 0;
    
    
}


