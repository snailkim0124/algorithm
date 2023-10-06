#include <bits/stdc++.h>

using namespace std;

int dist[1005][100005]; // [시간, 지점]
int n, t, m;
int s, e;
const int INF = 987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t >> m;
	cin >> s >> e;

	for (int i = 0; i < n; i++) { // 초기화
		dist[0][i] = INF;
	}
	dist[0][s] = 0; //시작 지점

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			dist[i + 1][j] = dist[i][j];
		}
		for (int j = 0; j < m; j++) {
			int u, v, w;
			cin >> u >> v >> w; // 양방향
			dist[i + 1][v] = min(dist[i + 1][v], dist[i][u] + w);
			dist[i + 1][u] = min(dist[i + 1][u], dist[i][v] + w);
		}

	}

	if (dist[t][e] == INF) cout << -1;
	else cout << dist[t][e];

	return 0;
}