#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[105][105]; // 가중치
int route[105][105];
const int INF = 987654321;
vector<int> v;
void go(int start, int end) {
	if (!route[start][end]) {
		v.push_back(start);
		v.push_back(end);
		return;
	}
	go(start, route[start][end]);
	v.pop_back();
	go(route[start][end], end);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 105 * 105, INF); // 무한대 값으로 초기화

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					route[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << 0 << " ";
			else {
				if (dist[i][j] == INF) cout << 0 << " ";
				else cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << 0 << " ";
			else {
				if (dist[i][j] == INF) cout << 0 << " ";
				else {
					v.clear();
					go(i, j);
					cout << v.size() << " ";
					for (auto it : v) {
						cout << it << " ";
					}
				}
			}
			cout << "\n";
		}
	}
	return 0;
}