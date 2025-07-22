#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
vector<int> adj[1005];
int visited[1005];

void dfs(int now) {
	visited[now] = 1;
	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		for (int i = 0; i < 1005; i++) {
			adj[i].clear();
		}
		memset(visited, 0, sizeof(visited));

		int n, m; // node, edge
		int cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}

		if (cnt == 1 && m == n - 1) cout << "tree\n"; // 한 번만에 순회하는지? 간선 = 노드 - 1 인지?
		else cout << "graph\n";
	}

	

	return 0;
}