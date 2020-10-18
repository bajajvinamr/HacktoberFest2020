#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define print(v) for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
void solve(){
    unordered_map<int,int> m;
    int N,K,tables=1,ans;
    cin>>N>>K;
    int F[N];
    for(int i=0;i<N;i++){
        cin>>F[i];
        m[F[i]]++;
    }
    vector<int> v;
    for(int i=0;i<N;i++){
        if(auto it=find(v.begin(),v.end(),F[i])!=v.end()){
            tables++;
            v.clear();
            v.push_back(F[i]);
        }
        else{
            v.push_back(F[i]);
        }
        //print(v);
        //cout<<endl;
    }
    int c=0;
    for(auto i:m){
        if(i.second>1)
            c+=i.second;
    }
    ans=min(tables*K,K+c);
    cout<<ans<<endl;
}
int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
