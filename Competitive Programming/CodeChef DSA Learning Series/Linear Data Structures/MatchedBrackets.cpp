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
    run
    int n;
    cin>>n;
    string s="";
    f(i,0,n-1)
    {
        int a;
        cin>>a;
        if(a==1)    s=s+'(';
        else s=s+')';
    }
    stack<char> st;
    int ans1=-1,ans2=-1,ans2i=-1,ans1i=-1,c1=0,c2=0;
    f(i,0,n-1)
    {
        if(s[i]=='(')
        {
            st.push('(');
            c1++;
            c2++;
        }
        if(s[i]==')')
        {
            st.pop();
            if(c1>ans1) {ans1=c1; ans1i=i;}
            c1--;
        }
        if(st.empty())
        {
            if(ans2<c2*2)   {ans2=c2*2; ans2i=i+2-ans2;}
            c2=0;
        }
    }
    cout<<ans1<<" "<<ans1i<<" "<<ans2<<" "<<ans2i;
    return 0;
}