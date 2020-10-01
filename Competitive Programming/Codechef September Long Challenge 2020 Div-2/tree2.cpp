#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli a[n],i;
        for(i=0;i<n;i++)cin>>a[i];
        set<lli> s;
        for(i=0;i<n;i++){
            if(a[i]!=0)s.insert(a[i]);
        }
        cout<<s.size()<<endl;
    }
}