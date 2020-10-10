#include <bits/stdc++.h>
using namespace std;
#define LG 20
#define MAX_N 100005

int N, M, Q;
vector < pair < int , long long >> adj[MAX_N];

int dep[MAX_N], anc[LG][MAX_N];
long long dist[MAX_N], dist0[MAX_N], dist1[MAX_N];

void dfs(int u, int p)
{
    anc[0][u] = p;
    for (int i = 1; i < LG; i++)
        anc[i][u] = anc[i - 1][anc[i - 1][u]];

    for (auto &ed : adj[u])
    {	
    	if (ed.first != p)
    	{
        	int v = ed.first;
        	dep[v] = dep[u] + 1;
        	dist[v] = dist[u] + ed.second;
        	dist0[v] = dist0[u];
        	dist1[v] = dist1[u];
        	if (ed.second & 1) dist1[v] += ed.second;
        		else dist0[v] += ed.second;
        	dfs(v, u);
    	}
    }
}

int getlca (int u, int v)
{
    if (dep[u] > dep[v])
    	swap(u, v);
    for (int i = LG - 1; i >= 0; i--)
        if (dep[v] - (1 << i) >= dep[u])
            v = anc[i][v];
    if (u == v)
    	return u;
    for (int i = LG - 1; i >= 0; i--)
        if (anc[i][u] != anc[i][v])
            u = anc[i][u], v = anc[i][v];
    
    return anc[0][u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N >> M >> Q;
    
    for (int i = 0; i < M; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dep[1] = dist[1] = dist0[1] = dist1[1] = 0;
    
    dfs(1, 1);

    while (Q--) {
        int u, v; cin >> u >> v;
        int lca = getlca(u, v);
        long long total = dist[u] + dist[v] - 2 * dist[lca];
        long long ans;
        if (total & 1)
            ans = dist0[u] + dist0[v] - 2 * dist0[lca];
        else
            ans = dist1[u] + dist1[v] - 2 * dist1[lca];
        cout << ans << "\n";
    }

    return 0;
}