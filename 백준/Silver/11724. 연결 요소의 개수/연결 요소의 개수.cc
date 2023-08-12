#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[1004];
int visited[1004];
int n, m;
int cnt;

void dfs(int v) {
	visited[v] = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		int idx = adj[v][i];
		if (visited[idx] == 0) dfs(idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
	return 0;
}