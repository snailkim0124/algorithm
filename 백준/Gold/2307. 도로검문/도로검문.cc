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
int dist[1005], memo[1005];
vector<tii> edge;
vector<pii> adj[1005];
const int INF = 987654321;

void dijkstra(int nu, int nv) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill(dist, dist + 1005, INF);

	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue;

		for (auto [next_dist, next] : adj[now]) {
			// 막은 간선은 지나치기
			if ((now == nu && next == nv) || (now == nv && next == nu)) continue;

			if (dist[next] > now_dist + next_dist) {
				dist[next] = now_dist + next_dist;
				memo[next] = now;
				pq.push({ dist[next], next });
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({ t, b });
		adj[b].push_back({ t, a });
		edge.push_back({ a, b, t });
	}

	// 처음 다익스트라
	dijkstra(-1, -1);

	if (dist[n] == INF) {
		cout << -1 << "\n";
		exit(0);
	}

	int first_dist = dist[n];

	// 역추적
	vector<pii> v;
	for (int now = n; now != 1; now = memo[now]) {
		v.push_back({ now, memo[now] });
	}

	int res = 0;
	for (auto [a, b] : v) {
		dijkstra(a, b);
		if (dist[n] == INF) {
			cout << -1 << "\n";
			exit(0);
		}
		res = max(res, dist[n] - first_dist);
	}
	
	cout << res << "\n";

	return 0;
}