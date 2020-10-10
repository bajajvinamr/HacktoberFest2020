//MD. HASNAIN ALI (UNSOLVED)
//I am nobody.
 
#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC               optimize ("Ofast")
#pragma GCC               optimize("O3")
#define ll                long long
#define lo(i,a,n,x)       for(i=a;i<=n;i=i+x)
#define loi(i,a,n,x)      for(i=a;i>=n;i=i-x) 
#define sca(n)            scanf("%lld", &n)
#define pri(n)            printf("%lld", n)
#define pb(a)             push_back(a)
#define pop()             pop_back()
#define mp                make_pair
#define ff                first
#define ss                second
#define sqr(x)            (x)*(x)
#define VI                vector <int>
#define SZ(a)             (int)a.size()
#define SORT(x)           sort(x.begin(), x.end())
#define REV(x)            reverse(x.begin(), x.end())
#define UNIQUE(v)         (v).erase(unique((v).begin(),(v).end()),(v).end())
#define REV(x)            reverse(x.begin(), x.end())
#define all(x)            x.begin(), x.end()
#define ODD(x)            ((x)&1)==0?(0):(1)
#define TEST_CASE(t)      for(int z=1;z<=t;z++)
#define distance(a,b)     (sq(a.x-b.x) + sq(a.y-b.y))
#define GCD(a, b)         __gcd(a, b)
#define lcm(a, b)         (a)*((b)/gcd(a,b))
#define end0              "\n"
#define end1              cout<<"\n";
#define pi                acos(-1)
#define mod               1000000007
#define inf               999999999999999999
#define eps               10e-9
 
 
ll nCr(ll n,ll r)
{
    int p=1,k=1,x;
    if(n<r) return 0;
    if(n-r<r) r=n-r;
    if(r!=0){
        while(r){
            p*=n;
            k*=r;
            x=__gcd(p,k);
            p/=x;
            k/=x;
            n--;
            r--;
        }
    }
    return p;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen("input-1.txt","r",stdin);
    //freopen("output-1.txt","w",stdout);
 
    
    ll i,j,a,b,c,d,s;
    string x,y;
    cin>>x>>y;
    a=x.length();
    b=0;
    lo(i,0,a-1,1){
        if(x[i]=='+') b++;
        else b--;
    }
    c=0;
    d=0;
    lo(i,0,a-1,1){
        if(y[i]=='+') c++;
        else if(y[i]=='-') c--;
        else d++;
    }
    s=abs(b-c);
    double ans=0;
    if(s>d) ans=0;
    else{
        s=(d+s)/2;
        ans=(nCr(d,s))/(double)pow(2,d);
    }
 
    cout<<fixed<<setprecision(12)<<ans<<end0;
 
 
    return 0;
}
