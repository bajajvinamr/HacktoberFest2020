#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   string s;
   cin>>s;
   int x=0,y=s.size();
   for(int i=y-1;i>=0;i--){
         if(s[i]=='1')
         x++;
   }
   if(x>1 && y%2!=0)
   cout<<y/2+1;
   else if(x>1 && y%2==0)
   cout<<y/2;
   else if(x==1)
   cout<<y/2;
   else
   {
         cout<<0;
   }
   
      
}
