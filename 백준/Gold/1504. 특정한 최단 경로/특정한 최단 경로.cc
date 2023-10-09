#include <bits/stdc++.h>

using namespace std;
int N, E;
int dist[805]; // 가중치
int v1, v2;
const int INF = 987654321;
vector<pair<int, int>> adj[805];
int res = INF;

void dijkstra(int start) {
	fill(dist, dist + 805, INF); // 무한대 값으로 초기화
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start)); // 가중치, 시작 위치
	dist[start] = 0;
	while (!pq.empty()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue; // 마지막 정점인가
		for (pair<int, int> there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			if (dist[_there] > dist[here] + _dist) { // 더 작으면 갱신
				dist[_there] = dist[here] + _dist;
				pq.push(make_pair(dist[_there], _there));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w; // u에서 v까지 가중치 w
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
		adj[v].push_back(make_pair(w, u));
	}

	cin >> v1 >> v2;

	dijkstra(1);
	int starttov1 = dist[v1];
	int starttov2 = dist[v2];

	dijkstra(v1);
	int v1tov2 = dist[v2];
	int v1toN = dist[N];

	dijkstra(v2);
	int v2toN = dist[N];

	res = min(res, starttov1 + v1tov2 + v2toN);
	res = min(res, starttov2 + v1tov2 + v1toN);

	if (res == INF || v1tov2 == INF) cout << -1;
	else cout << res;

	return 0;
}