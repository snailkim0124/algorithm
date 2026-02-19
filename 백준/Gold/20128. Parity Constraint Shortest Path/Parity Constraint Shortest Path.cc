#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m;
ll dist[100005][2]; // 가중치, 상태(짝, 홀)
const ll INF = LLONG_MAX;
vector<pll> adj[100005];
priority_queue<tll, vector<tll>, greater<tll>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}

	fill(&dist[0][0], &dist[0][0] + 100005 * 2, INF); // 무한대 값으로 초기화

	pq.push({ 0, 0, 1 }); // 가중치, 현재 상태, 시작 위치

	dist[1][0] = 0; // 첫 시작은 짝수

	while (!pq.empty()) {
		auto [now_dist, now_p, now] = pq.top();
		pq.pop();

		if (dist[now][now_p] != now_dist) continue;

		for (auto [next_dist, next] : adj[now]) {
			ll p = (now_dist + next_dist) % 2;

			if (dist[next][p] > dist[now][now_p] + next_dist) {
				dist[next][p] = dist[now][now_p] + next_dist;
				pq.push({ dist[next][p], p, next });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << (dist[i][1] == INF ? -1 : dist[i][1]) << " " << (dist[i][0] == INF ? -1 : dist[i][0]) << "\n";
	}
	
	
	return 0;
}