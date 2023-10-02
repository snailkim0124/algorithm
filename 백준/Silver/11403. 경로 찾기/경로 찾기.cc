#include <bits/stdc++.h>

using namespace std;

int n;
int dist[105][105]; // 가중치
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 105 * 105, INF); // 무한대 값으로 초기화

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				dist[i][j] = 1;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j랑  i -> k -> j를 비교
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}