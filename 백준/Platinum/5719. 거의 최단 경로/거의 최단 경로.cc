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
vector<pii> adj[505];
vector<int> memo[505];
int dist[505], visited[505];
int removed[505][505];

void dijkstra(int s, int e) {
	fill(dist, dist + 505, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue;
		for (auto [next, next_dist] : adj[now]) {
			if (removed[now][next]) continue; // 없는 경로면 넘어가기

			if (dist[next] > dist[now] + next_dist) {
				memo[next].clear(); // 새로운 최단 경로
				memo[next].push_back(now);

				dist[next] = dist[now] + next_dist;
				pq.push({ dist[next], next });
			}
			else if (dist[next] == dist[now] + next_dist) {
				memo[next].push_back(now); // 최단 경로 여러개 가능
			}
		}
	}
}

void solve() {
	int s, e;
	cin >> s >> e;
	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		adj[u].push_back({ v, p });
	}

	// 최단 경로 구하기
	dijkstra(s, e);

	// 최단 경로의 경로 없애기
	queue<int> q;
	q.push(e);

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now == s) continue;

		for (auto prev : memo[now]) {
			if (!removed[prev][now]) {
				removed[prev][now] = 1;
				q.push(prev);
			}
		}
	}

	// 한번 더 최단 경로 구하기
	dijkstra(s, e);

	//cout << "ans : " << dist[e] << "\n";

	if (dist[e] == INF) cout << -1 << "\n";
	else cout << dist[e] << "\n";
	
	memset(removed, 0, sizeof(removed));
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		memo[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;
		solve();
	}

	return 0;
}