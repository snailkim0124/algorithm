#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[55][55]; // 가중치
const int INF = 987654321;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 55 * 55, INF); // 무한대 값으로 초기화

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == 'Y') {
				dist[i][j] = 1;
			}
			else if (c == 'N') {
				dist[i][j] = INF;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (dist[i][j] <= 2) tmp++;
		}
		cnt = max(cnt, tmp);
	}

	cout << cnt;
	return 0;
}