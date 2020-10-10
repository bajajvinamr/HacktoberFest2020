#include<bits/stdc++.h>
using namespace std;

#define v(type) vector<type> 
#define map(type1,type2) map<type1,type2>
#define INF 1000000005
#define pb push_back
#define mp make_pair
#define f0(i,n) for(i = 0; i < ( n ); i ++)
#define f1(i,n) for(i = 1; i <= ( n ); i ++)
#define f(i,m,n) for(i = ( m ); i <= ( n ); i ++)
#define nl cout<<endl

typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    int T;
    cin>>T;
    int xyz;
    f(xyz,0,T-1)
    {
        int N;
        cin>>N;
        int i;
        ll max=0;
        f(i,1,N)
        {
            ll S,P,V;
            cin>>S>>P>>V;
            S++;
            ll ans=(P/S)*V;
            max=(ans>max)?ans:max;
        }
        cout<<max;
        nl;
    }
    return 0;
}