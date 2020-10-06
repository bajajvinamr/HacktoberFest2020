#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
      ll n,i,x,y,j;
      cin>>n;
      vector<pair<ll,ll>>vect;
      vect.push_back(make_pair(0,0));
      for(i=0;i<n;i++)
       {
      cin>>x>>y;
      vect.push_back(make_pair(x,y));
       }
       string a;
       ll f=1;
       sort(vect.begin(),vect.end());
       for(i=0;i<n;i++)
       {
          x=vect[i+1].first-vect[i].first;
          y=vect[i+1].second-vect[i].second;
          
           if(x>=0&&y>=0)
           {
               for(j=0;j<x;j++)
                a=a+"R";
               
               for(j=0;j<y;j++)
                a=a+"U";    
           }
           else
           {f=0;break;}
       }
     
       if(f==0)
        cout<<"NO"<<"\n";
       else
       {
           cout<<"YES"<<"\n";
           cout<<a<<"\n";
       }
  
  
    }
}
