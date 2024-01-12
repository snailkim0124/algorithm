#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[505][505]; // 가중치
const int INF = 987654321;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 505 * 505, INF); // 무한대 값으로 초기화

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j랑  i -> k -> j를 비교
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (dist[i][j] != INF || dist[j][i] != INF) cnt++;
			}
		}
		if (cnt == n - 1) res++;
	}

	cout << res;

	return 0;
}