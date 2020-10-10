#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fill fill_n
#define pf push_front
#define pb push_back
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define comp(v) (v).begin(),(v).end()
#define ff first
#define ss second
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<pair<int,int>> vpi;

const int M = 1e9+7;
const int N = 2e5;

vector<string> v;

void check(string s){
    string ans;
    int done[105]={0};
    for(auto i:v){
        if(s.substr(0,i.size())==i && !done[i.size()]){
            ans += 'P';
            done[i.size()]=1;
        }
        else if(s.substr(s.size()-i.size(),i.size())==i){
            ans += 'S';
        }
        else return;
    }
    
    cout<<ans<<"\n";
    exit(0);
}

void solve(){
    int n;cin>>n;
    v.resize(2*n-2);
    vector<string> big;
    FOR(i,0,2*n-2){
        cin>>v[i];
        if(v[i].size()==n-1){
            big.pb(v[i]);
        }
    }
    
    check(big[0][0] + big[1]);
    check(big[1][0] + big[0]);
    

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



