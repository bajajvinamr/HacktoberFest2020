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

int n,l;
int a[N];
double getl(double T){
    double x=0;
    int speed=1;
    FOR(i,0,n){
        double t = (double)(a[i]-x)/speed;
        if(t < T){
            T-=t;
            x=a[i];
            speed++;
        }
        else{
            return x + speed*T;
        }
    }
    return x + speed*T;
}
double getr(double T){
    double x=l;
    int speed=1;
    ROF(i,n-1,0){
        double t = (double)(x-a[i])/speed;
        if(t<T){
            T-=t;
            x=a[i];
            speed++;
        }
        else{
            return x - speed*T;
        }
    }
    return x-speed*T;
    
    
}

bool check(double x){
    return getl(x)<=getr(x);
}


void solve(){
    
    cin>>n>>l;
    FOR(i,0,n){
        cin>>a[i];
    }
   
    double tl=0,tr=l,mid;
    FOR(i,0,100){
        mid = tl + (tr-tl)/2;
        if(check(mid)) tl=mid;
        else tr=mid;
    }
    
    cout<<setprecision(20)<<tl<<"\n";
    
        

}




int main() {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
    
   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin);  
   freopen("output.txt", "w", stdout); 
   #endif 

    int t=1;
    cin>>t;
    FOR(i,1,t+1){
        //cout<<"Case #"<<i<<": "; 
        solve();
        
    }
    
    return 0;
    
    
}



