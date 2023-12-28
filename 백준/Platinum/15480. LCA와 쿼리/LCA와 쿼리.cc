#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> tree[100005];
int parent[20][100005]; // 희소 행렬
int visited[100005], depth[100005];
int m;

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	for (int i = 19; i >= 0; i--) {
		if ((depth[a] - depth[b]) & (1 << i)) {
			a = parent[i][a];
		}
	}

	for (int i = 19; i >= 0 && a != b; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	if (a != b) { // 부모가 끝까지 다른 경우
		a = parent[0][a];
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
				parent[0][next] = now; // 한칸 전진한 경우
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

	// 부모 배열 초기화
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp = parent[i - 1][j];
			parent[i][j] = parent[i - 1][tmp];
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int tmp1, tmp2, tmp3;
		int res;
		int r, u, v;
		cin >> r >> u >> v;
		tmp1 = lca(r, u);
		tmp2 = lca(u, v);
		tmp3 = lca(v, r);

		// 깊이가 깊은 곳이 기준
		if (depth[tmp1] >= depth[tmp2]) {
			res = tmp1;
			if (depth[tmp3] >= depth[res]) {
				res = tmp3;
			}
		}
		else {
			res = tmp2;
			if (depth[tmp3] >= depth[res]) {
				res = tmp3;
			}
		}
		cout << res << "\n";
	}

	return 0;
}