#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m<=n/2&&n!=1)
    cout<<m+1;
    else if(n!=1)
    cout<<m-1;
    else
    cout<<1;
        
}
