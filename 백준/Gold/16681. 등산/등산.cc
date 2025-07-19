#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M, D, E;
const ll INF = 10e16;
ll sdist[100005];
ll edist[100005];
ll height[100005];
vector<pll> adj[100005];
ll mx = -INF;

void Dijkstra(ll start, ll dist[]) {
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		ll here = pq.top().second;
		ll here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (pll there : adj[here]) {
			ll _dist = there.first;
			ll _there = there.second;
			if (dist[_there] > dist[here] + _dist && height[_there] > height[here]) {
				dist[_there] = dist[here] + _dist;
				pq.push({ dist[_there], _there });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(sdist, sdist + 100005, INF);
	fill(edist, edist + 100005, INF);

	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
	}

	for (int i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	Dijkstra(1, sdist); // 시작에서 목표까지
	Dijkstra(N, edist); // 끝에서 목표까지

	for (int i = 1; i <= N; i++) {
		if (sdist[i] == INF || edist[i] == INF) continue;
		mx = max(mx, height[i] * E - (sdist[i] + edist[i]) * D);
	}

	if (mx == -INF) cout << "Impossible";
	else cout << mx;

	return 0;
}