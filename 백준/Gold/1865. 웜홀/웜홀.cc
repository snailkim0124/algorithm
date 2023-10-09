#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T;
int N, M, W;
ll dist[1005];
const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> T;
	while (T--) {
		fill(dist, dist + 1005, INF);
		vector<pair<ll, ll>> adj[1005];

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back({ e, t });
			adj[e].push_back({ s, t });
		}

		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back({ e, -t });
		}

		dist[1] = 0;
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			for (int here = 1; here <= N; here++) {
				for (pair<int, int> there : adj[here]) {
					int _dist = there.second;
					int _there = there.first;
					if (dist[_there] > dist[here] + _dist) {
						if (i == N) q.push(_there);
						dist[_there] = dist[here] + _dist;
					}
				}
			}
		}

		if (!q.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}