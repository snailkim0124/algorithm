#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n, m;
vector<pii> adj[1005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int memo[1005];
int dist[1005];
vector<pii> path;

void dijkstra(int s, int u, int v) {
	fill(dist, dist + 1005, INF);
	pq.push({ 0, s }); // 가중치, 시작위치
	dist[s] = 0;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue;

		for (auto [next_dist, next] : adj[now]) {
			if ((u == now && v == next) || (u == next && v == now)) continue;
			if (dist[next] > dist[now] + next_dist) {
				dist[next] = dist[now] + next_dist;
				memo[next] = now;
				pq.push({ dist[next], next });
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back({ z, y });
		adj[y].push_back({ z, x });
	}
	

	dijkstra(1, -1, -1);
	for (int now = n; now != 1; now = memo[now]) {
		path.push_back({ now, memo[now] });
	}

	int mx = -1;
	for (auto [u, v] : path) {
		dijkstra(1, u, v);
		mx = max(mx, dist[n]);
	}

	cout << mx << "\n";

	/*dijkstra(n, dist2);
	for (int i = 1; i <= n; i++) {
		cout << i << " : " << dist2[i] << "\n";
	}*/

	return 0;
}