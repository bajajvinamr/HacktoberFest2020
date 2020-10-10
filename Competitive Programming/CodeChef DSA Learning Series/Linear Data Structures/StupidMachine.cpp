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
#define f(i,m,n) for(int i = ( m ); i <= ( n ); i ++)
#define run ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl cout<<"\n";

typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int&x:v)    cin>>x;
        ll s=v[0];
        int m=v[0];
        f(i,1,n-1)
        {
            s=s+min(m,v[i]);
            m=min(m,v[i]);
        }
        cout<<s;
        nl;
    }
    return 0;
}
