#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, k, s, t;
ll dist[100005]; // 가중치
const ll INF = LLONG_MAX;
vector<tll> adj[100005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k >> s >> t;
	for (int i = 0; i < m; i++) {
		ll u, v, c, p;
		cin >> u >> v >> c >> p;
		adj[u].push_back({ v, c, p });
	}

	fill(dist, dist + 100005, INF); // 무한대 값으로 초기화

	pq.push({ 0, s }); // 가중치, 시작 위치
	dist[s] = 0;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue;

		for (auto [next, nc, np] : adj[now]) {
			if (now_dist % np == 0 && dist[next] > dist[now] + nc) {
				dist[next] = dist[now] + nc;
				pq.push({ dist[next], next });
			}
		}
	}

	cout << (dist[t] == INF ? -1 : dist[t]) << "\n";


	return 0;
}