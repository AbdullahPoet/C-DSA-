#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
int vis[N];

void dfs(int u, int vis[], stack<int> &st) {
	vis[u] = true;
	for (auto v : adj[u]) {
		if (!vis[v]) {
			dfs(v, vis, st);
		}
	}
	st.push(u);
}

int32_t main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	stack<int> st;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, vis, st);
		}
	}

	vector<int> topoSort;
	while (!st.empty()) {
		topoSort.push_back(st.top());
		st.pop();
	}

	for (auto t : topoSort) {
		cout << t << " ";
	}
	cout << endl;
}