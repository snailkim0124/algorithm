#include <bits/stdc++.h>

using namespace std;

int n, k, s;
int dist[405][405]; // 가중치
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 405 * 405, INF); // 무한대 값으로 초기화

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = -1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
				else if (dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
			}
		}
	}

	cin >> s;
	while (s--) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] == INF) cout << 0 << "\n";
		else cout << dist[a][b] << "\n";
	}
	return 0;
}