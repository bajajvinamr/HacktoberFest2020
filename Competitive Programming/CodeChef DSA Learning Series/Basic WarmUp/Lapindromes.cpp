/*
₳₭₷₶!₸

████████╗██╗░░░██╗███╗░░██╗███████╗░█████╗░██╗░░██╗██╗
╚══██╔══╝██║░░░██║████╗░██║██╔════╝██╔══██╗██║░░██║██║
░░░██║░░░██║░░░██║██╔██╗██║█████╗░░██║░░╚═╝███████║██║
░░░██║░░░██║░░░██║██║╚████║██╔══╝░░██║░░██╗██╔══██║██║
░░░██║░░░╚██████╔╝██║░╚███║███████╗╚█████╔╝██║░░██║██║
░░░╚═╝░░░░╚═════╝░╚═╝░░╚══╝╚══════╝░╚════╝░╚═╝░░╚═╝╚═╝
*/

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
    loopt
    {
        string s;
        cin>>s;
        int n=s.length();
        int i=0;
        int j=n/2;
        if(n&1) j++;
        string s1="";
        string s2="";
        for(i=0;i<n/2;i++)  s1=s1+s[i];
        for(;j<n;j++)   s2=s2+s[j];
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2)
            cout<<"YES";
        else    cout<<"NO";
        nl;
    }
    return 0;
}