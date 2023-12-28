#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
vector<int> tree[50005];
int parent[50005], visited[50005], depth[50005];

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

	for (int i = 1; i <= 2000; i++) {
		tree[i].push_back(i * 2);
		tree[i].push_back(i * 2 + 1);
	}

	bfs(1);

	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) * 10 << "\n";
	}

	return 0;
}