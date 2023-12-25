#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int k;
vector<int> adj[20005];
int visited[20005];
int graph[20005];
bool check;

void dfs(int here) {
	visited[here] = 1;
	for (int there : adj[here]) {
		if (!visited[there]) {
			if (graph[here] == 0) {
				graph[there] = 1;
			}
			else if (graph[here] == 1) {
				graph[there] = 0;
			}
			dfs(there);
		}
		else if (graph[here] == graph[there]) { // 탐색하다가 발견한 경우
			check = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	while (k--) {
		for (int i = 0; i < 20005; i++) {
			adj[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(graph, 0, sizeof(graph));
		check = true; // 이분 그래프
		int V, E;
		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (check) {
				dfs(i);
			}
			else break;
		}

		if (check) cout << "YES\n";
		else cout << "NO\n";
	}



	return 0;
}