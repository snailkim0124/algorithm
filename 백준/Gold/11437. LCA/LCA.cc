#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> tree[50005];
int parent[50005], visited[50005], depth[50005];
int m;

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	while (depth[a] != depth[b]) {
		a = parent[a];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void bfs(int here) {
	visited[here] = 1;
	queue<int> q;
	q.push(here);
	int level = 1;
	int size = 1;
	int cnt = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : tree[now]) {
			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
				parent[next] = now;
				depth[next] = level;
			}
		}
		cnt++;
		if (cnt == size) {
			cnt = 0;
			size = q.size();
			level++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs(1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}