#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> tree[40005];
int parent[20][40005]; // 희소 행렬
int visited[40005], depth[40005];
int dist[20][40005]; // 거리
int m;

int lca(int a, int b) {
	int res = 0;
	if (depth[a] < depth[b]) swap(a, b);

	for (int i = 19; i >= 0; i--) {
		if ((depth[a] - depth[b]) & (1 << i)) {
			res += dist[i][a];
			a = parent[i][a];
		}
	}

	for (int i = 19; i >= 0 && a != b; i--) {
		if (parent[i][a] != parent[i][b]) {
			res += dist[i][a] + dist[i][b];
			a = parent[i][a];
			b = parent[i][b];
		}
	}


	if (a != b) { // 부모가 끝까지 다른 경우
		//a = parent[0][a];
		res += dist[0][a] + dist[0][b];
	}

	return res;
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
		for (auto next : tree[now]) {
			if (!visited[next.first]) {
				visited[next.first] = 1;
				q.push(next.first);
				dist[0][next.first] = next.second;
				parent[0][next.first] = now; // 한칸 전진한 경우
				depth[next.first] = level;
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
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	bfs(1);

	// 부모 배열 초기화
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp = parent[i - 1][j];
			parent[i][j] = parent[i - 1][tmp];
			dist[i][j] = dist[i - 1][j] + dist[i - 1][tmp]; // 거리 배열 초기화
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}