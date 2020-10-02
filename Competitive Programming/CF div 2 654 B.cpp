#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        long long int n,r;
        cin>>n>>r;
        
        if(r<n)
        {
            cout<<r*(r+1)/2<<endl;
        }
        else
        {
            cout<<n*(n-1)/2 +1<<endl;
        }
    }

    return 0;
}