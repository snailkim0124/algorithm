#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, v;

vector<int> adj[100001];
int visited_bfs[100001];
int visited_dfs[100001];
vector<int> result_bfs;
vector<int> result_dfs;
int cnt_dfs;
int cnt_bfs;

void dfs(int r) {
	visited_dfs[r] = 1;
	result_dfs.push_back(r);

	for (int i = 0; i < adj[r].size(); i++) {
		if(!visited_dfs[adj[r][i]])	dfs(adj[r][i]);
	}
	return;
}


void bfs(int r) {
	queue<int> q;
	q.push(r);
	visited_bfs[r] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		result_bfs.push_back(here);

		for (int i = 0; i < adj[here].size(); i++) {
			if (!visited_bfs[adj[here][i]]) {
				q.push(adj[here][i]);
				visited_bfs[adj[here][i]] = 1;
			}
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	bfs(v);
	for (int i = 0; i < result_dfs.size(); i++) {
		cout << result_dfs[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < result_bfs.size(); i++) {
		cout << result_bfs[i] << " ";
	}

	return 0;
}