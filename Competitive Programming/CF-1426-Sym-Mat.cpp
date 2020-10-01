#include <bits/stdc++.h>
typedef long long ll;
#define test int t;cin>>t;while(t--)
using namespace std;
 
int main(){
    test
    {
        ll n,m;
        cin>>n>>m;
        bool flag = 0;
        for(ll i=0;i<n;i++){
               ll temp1,temp2,temp3,temp4;
               cin>>temp1>>temp2>>temp3>>temp4;
               if(temp2 == temp3){
                   flag = 1;
               }
           }
        if(m %2 == 0 ){
           if(flag) cout<<"YES"<<"\n";
           else 
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
 
    }
}
