#include<bits/stdc++.h>
using namespace std;
void solve(){
    int N,K,ans=INT_MAX,start=-1;
    cin>>N>>K;
    int P[N];
    for(int i=0;i<N;i++)
        cin>>P[i];
    sort(P,P+N);
    bool flag=true;
    for(int i=0;i<N;i++){
        if(K%P[i]==0){
            int j;
            j=K/P[i];
            if(ans>j){
                ans=j;
                start=P[i];
            }
        }
    }
    cout<<start<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
