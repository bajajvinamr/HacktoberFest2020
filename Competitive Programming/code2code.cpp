#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> v;
    v.push_back(a);
        v.push_back(c);
            v.push_back(d);
            sort(v.begin(),v.end());
   long long int k =v[0];
   a=a-k;
   vector<int> x;
   x.push_back(a);
   x.push_back(b);
   long long int l=x[0];
   long long int z=k*256;
   long long int y=l*32;
   long long int m=y+z;
   cout<<m;
    
}
