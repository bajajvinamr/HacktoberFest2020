#include<bits/stdc++.h>
using namespace std;
void solve(){
    string S,P,a,b;
    char c='z',ch='z';
    cin>>S>>P;
    map<char,int> m,t;
    for(int i=0;i<S.size();i++){
        m[S[i]]++;
        t[S[i]]++;
    }
    for(int i=0;i<P.size();i++){
        m[P[i]]--;
        t[P[i]]--;
    }
    for(auto i:m){
        if(i.first>P[0])
            break;
        while(m[i.first]!=0){
                b+=i.first;
                m[i.first]--;
        }
    }
    b+=P;
    for(auto i:m){
        while(m[i.first]!=0){
                b+=i.first;
                m[i.first]--;
        }
    }
    for(auto i:t){
        if(i.first>=P[0])
            break;
        while(t[i.first]!=0){
                a+=i.first;
                t[i.first]--;
        }
    }
    a+=P;
    for(auto i:t){
        while(t[i.first]!=0){
                a+=i.first;
                t[i.first]--;
        }
    }
    string res;
    res=min(a,b);
    cout<<res<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
