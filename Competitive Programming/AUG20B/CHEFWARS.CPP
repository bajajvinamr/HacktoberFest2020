#include<bits/stdc++.h>
using namespace std;
void solve(){
    int P,H;
    cin>>H>>P;
    while(P!=0){
        H-=P;
        //cout<<H<<endl;
        P/=2;
        //cout<<P<<endl;
    }
    if(P<H)
        cout<<"0\n";
    else
        cout<<"1\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
