/////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include<bits/stdc++.h>
using namespace std;

#define INF 1000000005
#define mod ((int)1e9+7)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define f0(i,n) for(i = 0; i < ( n ); i ++)
#define f1(i,n) for(i = 1; i <= ( n ); i ++)
#define f(i,m,n) for(auto i = ( m ); i <= ( n ); i ++)
#define run ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl cout<<"\n";
#define loopt int t; cin>>t; while(t--)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> ii;
typedef pair<long long int,long long int> lili;
typedef vector<ii > vii;
typedef vector<lili> vll;
typedef vector<vi > viv;

/////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main()
{
    run
    loopt
    {
        ll k; ll d0,d1;
        cin>>k>>d0>>d1;
        if(k==2)
        {
            if((d0+d1)%3==0)    cout<<"YES";
            else cout<<"NO";
            nl;
            continue;
        }
        ll sum=(d0+d1)%10;
        int term=(sum*2)%10;
        sum=sum+d0+d1;
        ll ar[5]={0};
        ar[1]=term;
        ar[2]=(term*2)%10;
        ar[3]=(term*4)%10;
        ar[4]=(term*8)%10;
        ll sum1=((k-3)/4)*ar[1];
        if((k-3)%4!=0)  sum1+=ar[1];
        ll sum2=(((k-3)/4)+((k-3)%4)/2)*ar[2];
        ll sum3=(((k-3)/4)+((k-3)%4)/3)*ar[3];
        ll sum4=(((k-3)/4)*ar[4]);
        if((sum+sum1+sum2+sum3+sum4)%3==0)
            cout<<"YES";
        else cout<<"NO";
        nl;
    }
    return 0;
}
