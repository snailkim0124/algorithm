#include <bits/stdc++.h>

using namespace std;
int V, E, P;
int dist[10005]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[10005];

int dijkstra(int start, int end) {
	fill(dist, dist + 10005, INF); // 무한대 값으로 초기화
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

	return dist[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> P;

	for (int i = 0; i < E; i++) {
		int a, b, c; // a에서 b까지 가중치 c
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	int starttop = dijkstra(1, P);
	int ptoend = dijkstra(P, V);
	int starttoend = dijkstra(1, V);

	if (starttop + ptoend <= starttoend) {
		cout << "SAVE HIM";
	}
	else cout << "GOOD BYE";

	return 0;
}