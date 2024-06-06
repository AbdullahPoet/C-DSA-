#include<bits/stdc++.h>

using namespace std;


int32_t main() {
	int n, m; cin >> n >> m;
	vector<int> adj[n + 1];
	int indeg[n + 1];
	memset(indeg, 0, sizeof indeg);

	for (int i = 1; i <= n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topo_sort;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topo_sort.push_back(u);

		for (auto v : adj[u]) {
			indeg[v]--;
			if (indeg[v] == 0) {
				q.push(v);
			}
		}
	}

	for (auto it : topo_sort) {
		cout << it << " ";
	}
	cout << endl;
}