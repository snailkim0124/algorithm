#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
ll dist[505];
const ll INF = 1e18;
ll visited[505];
vector<pair<ll, ll>> adj[505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(dist, dist + 505, INF);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	dist[1] = 0;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		for (int here = 1; here <= N; here++) {
			for (pair<int,int> there : adj[here]) {
				int _dist = there.second;
				int _there = there.first;
				if (dist[here] != INF && dist[_there] > dist[here] + _dist) {
					if (i == N) q.push(_there);
					dist[_there] = dist[here] + _dist;
				}
			}
		}
	}

	if (!q.empty()) cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
	return 0;
}