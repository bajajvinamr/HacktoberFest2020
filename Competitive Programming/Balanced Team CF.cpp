#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
      cin>>a[i];
      sort(a,a+n);
     ll ptr1=0,ptr2=0,ans=0;
     for(;ptr2<n;)
     {
         if(a[ptr2]-a[ptr1]<=5)
          ptr2++;
         else
          ptr1++;
          if((ptr2-ptr1>ans))
           ans=ptr2-ptr1;
     }
     cout<<ans;
      
}
 
