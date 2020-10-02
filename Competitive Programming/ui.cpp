#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
signed main()
{
      fast
      int l,r,flag;
      cin>>l>>r;
      int k=l;
      while(k<=r){
            set<int> s;
            flag=0;
            l=k;
            while(l){
                  if(s.count(l%10)==1){
                        flag=1;
                        break;
                  }
                  s.insert(l%10);
                  l/=10;
            }
            if(flag){
                  k++;
            }
            else
            break;
      }
      if(flag==0){
            cout<<k;
      }
      else
      {
            cout<<-1;
      }
      
}
