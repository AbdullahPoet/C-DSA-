#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"


void dfs(int node, int vis[], vector<int> adj[]) {
	vis[node] = true;
	cout << node << " ";
	for (auto v : adj[node]) {
		if (!vis[v]) dfs(v, vis, adj);
	}
}
int32_t main() {
	int n, m; cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int vis[n + 1];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i, vis, adj);
	}
}

