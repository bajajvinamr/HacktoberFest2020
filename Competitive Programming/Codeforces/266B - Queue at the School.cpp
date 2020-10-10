//MD. HASNAIN ALI (UNSOLVED)
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC optimize("O3")
#define ll long long int
#define end "\n"
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define FastIO ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define eps 10e-9
#define MX 1000005

int main()
{
    //freopen("test.txt","r",stdin);

    string x;
    int a,b,i;
    cin>>a>>b>>x;

    while(b--)
    {
        for(i=0;i<a;i++)
        {
            if(x[i]=='B' && x[i+1]=='G')
            {
                x[i]='G';
                x[i+1]='B';
                i++;
            }
        }
    }

    cout<<x<<endl;

    return 0;
}










