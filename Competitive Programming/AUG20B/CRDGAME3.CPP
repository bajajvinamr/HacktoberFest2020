#include<bits/stdc++.h>
using namespace std;
int result(int a){
    int res=a/9;
    if(a%9)
        res++;
    return res;
}
void solve(){
    int pc,pr;
    cin>>pc>>pr;
    //cout<<result(pc)<<" "<<result(pr)<<endl;
    if(result(pc)>=result(pr))
        cout<<"1 "<<result(pr)<<endl;
    else
        cout<<"0 "<<result(pc)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
