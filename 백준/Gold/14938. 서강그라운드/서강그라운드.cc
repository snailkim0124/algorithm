#include <bits/stdc++.h>

using namespace std;

int n, m, r;
int dist[105][105]; // 가중치
int arr[105];
const int INF = 987654321;
int mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 105 * 105, INF); // 무한대 값으로 초기화

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j랑  i -> k -> j를 비교
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int tmp = arr[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else {
				// 수색 범위 내
				if (dist[i][j] <= m) {
					tmp += arr[j];
				}
			}
		}
		mx = max(mx, tmp);
	}

	cout << mx;

	return 0;
}