//link in codechef:https://www.codechef.com/COOK123B/problems/PATHSUMS/
 
#include<iostream>
#include<queue>
using namespace std;

vector<int> bfs(vector<vector<int>> adj,int N)
{
	int visited[N+1],temp;
	vector<int> ret(N+1);
	for(int i=1;i<=N;i++) visited[i]=0;
	queue<int> q;

	q.push(1); visited[1]=1;
	ret[1] = 1;

	while(q.empty()==0){
		temp = q.front();
		for(int i=0;i<adj[temp].size();i++){
			if(visited[adj[temp][i]] == 0){
				q.push(adj[temp][i]);
				visited[adj[temp][i]]=1;
				ret[adj[temp][i]] = ret[temp]%2==1?2:1;
			}
		}
		q.pop();
	}
return ret;
}

int main(){
	int T,N,u,v;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>N;
		vector<vector<int>> adj(N+1);
		for(int i=0;i<N-1;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> ans = bfs(adj,N);
		for(int i=1;i<=N;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
