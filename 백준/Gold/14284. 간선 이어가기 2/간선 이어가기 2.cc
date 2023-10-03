#include <bits/stdc++.h>

using namespace std;
int n, m;
int dist[5005]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[5005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int s, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(dist, dist + 5005, INF); // 무한대 값으로 초기화

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w; // u에서 v까지 가중치 w
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
		adj[v].push_back(make_pair(w, u));
	}

	cin >> s >> t;

	pq.push(make_pair(0, s)); // 가중치, 시작 위치
	dist[s] = 0;
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

	cout << dist[t];
	return 0;
}