#include <bits/stdc++.h>

using namespace std;
int N, M, K, X;
const int INF = 987654321;
int dist[300005];
vector<int> adj[300005];
queue<int> q;
bool check;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int u, v; // u에서 v까지
		cin >> u >> v;
		adj[u].push_back(v);
	}

	fill(dist, dist + 300005, INF);

	q.push(X); // 시작 위치
	dist[X] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int there : adj[here]) {
			int _there = there;
			if (dist[_there] > dist[here] + 1) { // 더 작으면 갱신
				dist[_there] = dist[here] + 1;
				q.push(_there);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			check = true;
			cout << i << "\n";
		}
	}

	if (!check) cout << -1;

	return 0;
}