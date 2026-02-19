#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, a, b;
ll dist[100005][2]; // 가중치, 상태
const ll INF = LLONG_MAX;
vector<pll> adj[100005];
priority_queue<tll, vector<tll>, greater<tll>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll s, e, t;
		cin >> s >> e >> t;
		adj[s].push_back({ t, e });
		adj[e].push_back({ t, s });
	}
	cin >> a >> b;


	fill(&dist[0][0], &dist[0][0] + 100005 * 2, INF); // 무한대 값으로 초기화

	pq.push({ 0, 0, a }); // 가중치, 현재 상태, 시작 위치
	pq.push({ 0, 1, a });

	dist[a][0] = 0;
	dist[a][1] = 0;
	while (!pq.empty()) {
		auto [now_dist, now_t, now] = pq.top();
		pq.pop();

		if (dist[now][now_t] != now_dist) continue;
		for (auto [t, next] : adj[now]) {
			
			if (dist[next][t] > dist[now][now_t] + (t != now_t)) {
				dist[next][t] = dist[now][now_t] + (t != now_t);
				pq.push({ dist[next][t], t, next});
			}
		}
	}

	cout << min(dist[b][0], dist[b][1]) << "\n";
	
	return 0;
}