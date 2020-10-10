/*
                ┈┈╱▔▔▔▔▔▔▔▏ 
                ┈╱╭▏╮ ╭┻┻╮╭┻┻╮╭▏ 
                ▕╮╰▏╯┃╭╮┃┃╭╮┃╰▏ 
                ▕╯┈▏┈┗┻┻┛┗┻┻┻╮▏ 
                ▕╭╮▏╮┈┈┈┈┏━━━╯▏
                ▕╰╯▏╯╰┳┳┳┳┳┳╯╭▏ 
                ▕┈╭▏╭╮┃┗┛┗┛┃┈╰▏ 
                ▕┈╰▏╰╯╰━━━━╯┈┈▏

████████╗██╗░░░██╗███╗░░██╗███████╗░█████╗░██╗░░██╗██╗
╚══██╔══╝██║░░░██║████╗░██║██╔════╝██╔══██╗██║░░██║██║
░░░██║░░░██║░░░██║██╔██╗██║█████╗░░██║░░╚═╝███████║██║
░░░██║░░░██║░░░██║██║╚████║██╔══╝░░██║░░██╗██╔══██║██║
░░░██║░░░╚██████╔╝██║░╚███║███████╗╚█████╔╝██║░░██║██║
░░░╚═╝░░░░╚═════╝░╚═╝░░╚══╝╚══════╝░╚════╝░╚═╝░░╚═╝╚═╝
*/

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
typedef vector<pair<int,int> > vii;
typedef vector<lili> vlili;
typedef vector<vector<int> > viv;

int main()
{
    run
    loopt
    {
        int n;  cin>>n;
        string s;   cin>>s;
        int a=n,b=n;
        int ga=0,gb=0;
        int f=1;
        f(i,0,s.length()-1)
        {
            if(i&1)
            {
                b--;
                if(s[i]=='1')    gb++;
                if((gb>ga+a)||(ga>gb+b))    {cout<<i+1; f=0; break;}
            }
            else
            {
                a--;
                if(s[i]=='1')    ga++;
                if((gb>ga+a)||(ga>gb+b))      {cout<<i+1; f=0; break;} 
            }
        }
        if(f==1)    cout<<s.length();
        nl;
    }
    return 0;
}