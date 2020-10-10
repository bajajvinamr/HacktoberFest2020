//MD. HASNAIN ALI (UNSOLVED)
#include<bits/stdc++.h>
using namespace std;

#pragma GCC             optimize ("Ofast")
#pragma GCC             optimize("O3")
#define ll              long long
#define l(i,a,n,x)      for(i=a;i<=n;i=i+x)
#define sca(n)          scanf("%lld", &n)
#define pri(n)          printf("%lld", n)
#define SORT(x)         sort(x.begin(), x.end())
#define REV(x)          reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define distance(a,b)   (sq(a.x-b.x) + sq(a.y-b.y))
#define end0             "\n"
#define end1            cout<<"\n";
#define pi              acos(-1)
#define mod             1000000007
#define inf             999999999999999999
#define eps             10e-9





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	//freopen("test.txt","r",stdin);


	int i,l,s=0,c=0;
	string x;
	cin>>x;
	l=x.length();
	for(i=0;i<l;i++){
        if(x[i]>=65 && x[i]<=90) c++;
        else s++;
	}
	if(c>s){
        for(i=0;i<l;i++)
        {
            x[i]&=95;
        }
	}
	else{
        for(i=0;i<l;i++)
        {
            x[i]|=32;
        }
	}

    cout<<x<<end0;



    return 0;
}

