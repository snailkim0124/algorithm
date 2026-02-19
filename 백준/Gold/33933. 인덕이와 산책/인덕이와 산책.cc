#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, t;
ll dist[1005]; // 가중치
ll dist_walk[1005][1005];
ll c[1005];
vector<ll> c_pos[1005];
const ll INF = LLONG_MAX;
vector<pll> adj[1005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back({ 1, b });
		adj[b].push_back({ 1, a });
	}

	for (int i = 0; i < t; i++) {
		cin >> c[i];
		c_pos[c[i]].push_back(i);
	}

	fill(dist, dist + 1005, INF); // 무한대 값으로 초기화

	pq.push({ 0, 1 }); // 가중치, 시작 위치
	dist[1] = 0;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue;

		// 다음 간선으로 이동하기
		for (auto [next_dist, next] : adj[now]) {
			if (dist[next] > dist[now] + next_dist) {
				dist[next] = dist[now] + next_dist;
				pq.push({ dist[next], next});
			}
		}
	}

	ll ans = INF;
	for (int i = 1; i <= n; i++) {
		// 이동한 후 사이클 타기
		if (dist[i] == INF || c_pos[i].empty()) continue;

		for (auto it : c_pos[i]) {
			ll tmp = dist[i] % t;
			ll d = (it - tmp + t) % t;

			ll mn = INF;
			for (auto n_it : c_pos[n]) {
				mn = min(mn, (n_it - it + t) % t);
			}

			if (mn != INF) {
				ll next_dist = dist[i] + d + mn;
				ans = min(ans, next_dist);
				//cout << i << " : " << next_dist << "\n";
			}
		}
	}

	fill(&dist_walk[0][0], &dist_walk[0][0] + 1005 * 1005, INF); // 무한대 값으로 초기화

	queue<pll> q;

	if (c[0] != 1) {
		q.push({ 1, 0 });
		dist_walk[1][0] = 0;
	}

	ll ans2 = INF;

	while (!q.empty()) {
		auto [now, now_dist] = q.front();
		q.pop();

		if (now == n) {
			ans2 = min(ans2, now_dist);
			break;
		}

		ll n_dist = now_dist + 1;
		
		// 1분 쉬기
		if (c[(n_dist % t)] != now && dist_walk[now][(n_dist % t)] == INF) {
			dist_walk[now][(n_dist % t)] = n_dist;
			q.push({ now, n_dist });
		}

		// 다른 지점으로 이동
		for (auto [next_dist, next] : adj[now]) {
			if (c[(n_dist % t)] != next && dist_walk[next][(n_dist % t)] == INF) {
				dist_walk[next][(n_dist % t)] = n_dist;
				q.push({ next, n_dist });
			}
		}
	}

	cout << (min(ans, ans2) == INF ? -1 : min(ans, ans2)) << "\n";

	return 0;
}