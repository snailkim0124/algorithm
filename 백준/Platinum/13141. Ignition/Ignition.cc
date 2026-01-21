#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int dist[205][205];
vector<pii> adj[205];
const int INF = 987654321;
double res = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 205 * 205, INF);

	cin >> n >> m;

	// 자기자신은 0
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int s, e, l;
		cin >> s >> e >> l;
		dist[s][e] = min(dist[s][e], l);
		dist[e][s] = min(dist[e][s], l);
		adj[s].push_back({ e, l });
		adj[e].push_back({ s, l });
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 시작점 완탐
	for (int s = 1; s <= n; s++) {
		double mx = 0;

		for (int u = 1; u <= n; u++) {
			for (auto [v, cost] : adj[u]) {
				mx = max(mx, (dist[s][u] + dist[s][v] + cost) / 2.0);
			}
		}
		// 최대 중 최소
		res = min(res, mx);
	}

	cout << fixed;
	cout.precision(1);
	cout << res << "\n";

	return 0;
}