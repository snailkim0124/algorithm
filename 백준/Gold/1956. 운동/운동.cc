#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[405][405]; // 가중치
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int mn = INF;
bool check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 405 * 405, INF); // 무한대 값으로 초기화

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j랑  i -> k -> j를 비교
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (dist[i][j] != INF && dist[j][i] != INF) {
				mn = min(mn, dist[i][j] + dist[j][i]);
				check = true;
			}
		}
	}

	if (check) cout << mn;
	else cout << -1;

	return 0;
}