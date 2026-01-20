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
vector<pii> adj[200005];
int dist[200005], visited[200005];
vector<int> memo;

void dijkstra(int s, int e) {
	fill(dist, dist + 200005, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue;
		for (auto [next, next_dist] : adj[now]) {
			if (visited[next]) continue; // 이미 방문한 최단경로면 패스

			if (dist[next] > dist[now] + next_dist) {
				dist[next] = dist[now] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}
}

void find_path(int s, int e) {
	int now = s;

	// 사전 순으로 경로 찾기
	while (now != e) {
		int mn = INF;
		for (auto [next, next_dist] : adj[now]) {
			if (visited[next]) continue;

			if (dist[now] == dist[next] + next_dist) {
				mn = min(mn, next);
			}
		}

		now = mn;
		memo.push_back(now);
	}

	// 방문 처리
	for (auto now : memo) {
		if (now == s || now == e) continue;
		visited[now] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int s, e;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	
	cin >> s >> e;
	dijkstra(e, s);
	int dist1 = dist[s];

	memo.push_back(s);
	find_path(s, e);

	dijkstra(s, e);
	int dist2 = dist[e];

	cout << dist1 + dist2 << "\n";


	return 0;
}