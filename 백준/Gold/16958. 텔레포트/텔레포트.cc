#include <bits/stdc++.h>

using namespace std;

typedef struct city {
	int s, x, y;
}city;

int n, t, m;
vector<city> v;
int dist[1005][1005]; // 가중치
const int INF = 987654321;

int distfunc(city a, city b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 1005 * 1005, INF); // 무한대 값으로 초기화

	cin >> n >> t;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		v[i] = { s, x, y };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int DIST = distfunc(v[i], v[j]);
			if (v[i].s == 1 && v[j].s == 1) { // 텔레포트 가능
				DIST = min(DIST, t);
			}
			dist[i][j] = DIST;
		}
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i -> j랑  i -> k -> j를 비교
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << "\n";
	}
	return 0;
}