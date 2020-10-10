//MD. HASNAIN ALI (UNSOLVED)
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
#define all(x)            x.begin(), x.end()
#define ODD(x)            ((x)&1)==0?(0):(1)
#define TEST_CASE(t)      for(int z=1;z<=t;z++)
#define distance(a,b)     (sq(a.x-b.x) + sq(a.y-b.y))
#define gcd(a, b)         __gcd(a, b)
#define lcm(a, b)         (a)*((b)/gcd(a,b))
#define end0              "\n"
#define end1              cout<<"\n";
#define pi                acos(-1)
#define mod               1000000007
#define inf               999999999999999999
#define eps               10e-9





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	//freopen("test.txt","r",stdin);
    
    ll t,i,j,n,a,b;
    cin>>t;
    TEST_CASE(t){
        cin>>n;
        int x[n];
        lo(i,0,n-1,1){
            cin>>x[i];
        }
        i=0;
        a=0;
        while(x[i]==1){
            a++;
            i++;
        }
            
        if(a==n){
            if(a%2==0) cout<<"Second"<<end0;
            else cout<<"First"<<end0;
        }
        else{
            if(a%2==0) cout<<"First"<<end0;
            else cout<<"Second"<<end0;
        }
    }


    return 0;
}
