#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld ans=0,m;

lld dfs(vector<lld> &cat,vector<vector <lld> > &adj,vector<lld> &vis,lld &node,lld ctr)
{
	if(vis[node]==1)
		return 0;

	if(cat[node])
		++ctr;
	else
		ctr=0;

	vis[node]=1;

	if(ctr>m)
		return 0;

	if(adj[node].size()==1&&node!=1)
		++ans;

	for(lld k=0;k<adj[node].size();++k)
		dfs(cat,adj,vis,adj[node][k],ctr);

	return 1;
}

int main()
{
	lld i,n,j,x,y;

	cin>>n>>m;

	vector<lld> cat(n+1,0);

	for(i=1;i<=n;++i)
		cin>>cat[i];

	vector<vector <lld> > adj(n+1);
	vector<lld> vis(n+1,0);

	for(j=0;j<n-1;++j)
	{
		cin>>x>>y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	lld node=1;
	dfs(cat,adj,vis,node,0);

	cout<<ans<<endl;
}
