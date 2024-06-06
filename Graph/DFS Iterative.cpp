#include<bits/stdc++.h>

using namespace std;

int32_t main() {
	int n, m; cin >> n >> m;
	vector<int> adj[n + 1];

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	bool vis[n + 1];
	memset(vis, 0, sizeof vis);
	stack<int> st;

	vector<int> dfs;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			st.push(i);
			vis[i] = true;
			while (!st.empty()) {
				int u = st.top();
				st.pop();
				dfs.push_back(u);

				for (auto v : adj[u]) {
					if (!vis[v]) {
						st.push(v);
						vis[v] = true;
					}
				}
			}
		}
	}

	for (auto it : dfs) {
		cout << it << " ";
	}

	cout << endl;
}