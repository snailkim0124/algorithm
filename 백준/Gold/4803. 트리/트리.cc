#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t = 1;
int n, m;
vector<int> adj[505];
int visited[505];

int dfs(int here, int prev) {
	visited[here] = 1;
	for (int there : adj[here]) {
		if (there == prev) continue;
		if (visited[there]) return 0;
		if (dfs(there, here) == 0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int cnt = 0;
		for (int i = 0; i < 505; i++) {
			adj[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if(dfs(i, 0)) cnt++;
			}
		}

		if (cnt == 0) cout << "Case " << t << ": No trees.\n";
		else if (cnt == 1) cout << "Case " << t << ": There is one tree.\n";
		else cout << "Case " << t << ": A forest of " << cnt << " trees.\n";
		t++;
	}

	return 0;
}