#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define endl '\n'
#define mod 1000000007

bool sorttt(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
    vector<int> v[10001];
    // int mx=0,node=-1;
    bool rec[10001];
    // int dis[100001]={0};
    // vector<int> vec[100001];
    // set<int> se;

// void dfs(int x,int c){
//     rec[x]=1;
//     rep(i,0,v[x].size()){
//         if(!rec[v[x][i]]&&arr[i]==1){
//             dfs(v[x][i],c+1);
//         }
//         else if(!rec[v[x][i]]&&arr[i]==0){
//             dfs(v[x][i],c);
//         }
//     }
//     if(c<=m)d++;
// }

void dfs(int x){
    rec[x]=true;
    for(int i=0;i<v[x].size();i++){
        if(!rec[v[x][i]]){ dfs(v[x][i]);}
    }
}
// bool bfs(int x, int n,int m){
//     int f=0;
//     bool vis[n+1];
//     rep(i,1,n+1) vis[i]=false;
//     vis[x]=true;
//     list<int> q;
//     q.pb(x);
//     while(!q.empty()){
//         int s=q.front();
//         if(s==m)f=1;
//         q.pop_front();
//         for(int i=0;i<v[s].size();i++){
//             if(!vis[v[s][i]]){
//                 vis[v[s][i]]=true;
//                 q.pb(v[s][i]);
//             }
//         }
//     }
//     if(f)return true;
//     return false;
// }

signed main()
{
    fast
    int n,ans=0,x; cin>>n;
    rep(i,1,n+1){
        cin>>x;
        v[i].pb(x);
        v[x].pb(i);
    }
    rep(i,1,n+1){
        if(!rec[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
}
