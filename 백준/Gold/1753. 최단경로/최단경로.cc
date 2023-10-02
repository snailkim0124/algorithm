#include <bits/stdc++.h>

using namespace std;
int V, E, K;
int dist[20005]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	cin >> K;

	fill(dist, dist + 20005, INF); // 무한대 값으로 초기화

	for (int i = 0; i < E; i++) {
		int u, v, w; // u에서 v까지 가중치 w
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}

	pq.push(make_pair(0, K)); // 가중치, 시작 위치
	dist[K] = 0;
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

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}