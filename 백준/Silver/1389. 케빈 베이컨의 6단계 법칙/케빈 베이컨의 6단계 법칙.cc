#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[105][105]; // 가중치
const int INF = 987654321;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 105 * 105, INF); // 무한대 값으로 초기화

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j랑  i -> k -> j를 비교
			}
		}
	}

	int mn = INF;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += dist[i][j];
			
		}
		if (mn > tmp) {
			mn = tmp;
			ans = i;
		}
	}

	cout << ans;
	return 0;
}