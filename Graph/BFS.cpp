#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"

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
		if (!vis[i]) {
			queue<int> q;
			q.push(i);
			vis[i] = true;
			while (!q.empty()) {
				int u = q.front();
				cout << u << " ";
				q.pop();
				for (auto v : adj[u]) {
					if (!vis[v]) {
						q.push(v);
						vis[v] = true;
					}
				}
			}
		}
	}
}

