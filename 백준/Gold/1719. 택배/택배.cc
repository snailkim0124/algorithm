#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[205][205]; // 가중치
int ans[205][205]; // 방향 배열
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 205 * 205, INF); // 무한대 값으로 초기화

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[a][b], c);
		ans[a][b] = b;
		ans[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					ans[i][j] = ans[i][k]; // 최소일 때 값을 저장
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "-" << " ";
			else {
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}