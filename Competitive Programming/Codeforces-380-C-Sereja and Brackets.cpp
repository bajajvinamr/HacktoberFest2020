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
const int N = 1e6;

string br;
typedef struct seg{
    int l=0,r=0,ans=0;
}seg;

seg tree[4*N+5];
void build(int n,int s,int e){
    if(s==e){
        if(br[s]=='('){
            tree[n].l++;
        }
        else{
            tree[n].r++;
        }
        
        return;
    }
    
    int mid = (s+e)>>1;
    build(2*n,s,mid);
    build(2*n+1,mid+1,e);
    tree[n].ans = tree[2*n].ans+tree[2*n+1].ans;
    int z = min(tree[2*n].l,tree[2*n+1].r);
    tree[n].ans += 2*z;
    tree[n].l = tree[2*n].l + tree[2*n+1].l - z;
    tree[n].r = tree[2*n].r + tree[2*n+1].r - z;
}
seg query(int n,int s,int e,int l,int r){
    if(s>r || e<l){
        seg p;
        p.l=0 ; p.r=0; p.ans = 0;
        return p;
    }
    if(s>=l && e<=r){
        return tree[n];
    }
    int mid = (s+e)>>1;
    seg p1 = query(2*n,s,mid,l,r);
    seg p2 = query(2*n+1,mid+1,e,l,r);
    seg p;
    p.ans = p1.ans + p2.ans;
    int z = min(p1.l,p2.r);
    p.ans += 2*z;
    p.l = p1.l + p2.l -z;
    p.r = p1.r + p2.r - z;
    return p;
}


void solve(){
    string s;
    cin>>s;
    br = '#'+ s;
    int n = br.length()-1;  
    int m;cin>>m;
    build(1,1,n);
    seg ans;
    while(m--){
        int l,r;
        cin>>l>>r;
        ans = query(1,1,n,l,r);
        cout<<ans.ans<<"\n";
    }

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

