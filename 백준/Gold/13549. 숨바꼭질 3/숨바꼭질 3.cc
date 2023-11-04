#include <bits/stdc++.h>

using namespace std;
int n, k;
int dist[100005]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	fill(dist, dist + 100005, INF); // 무한대 값으로 초기화

	for (int i = 0; i <= 100000; i++) {
		if (i - 1 >= 0) adj[i].push_back({ 1, i - 1 }); // 1초 후 이동
		if (i + 1 <= 100000) adj[i].push_back({ 1, i + 1 }); // 1초 후 이동
		if (2 * i <= 100000) adj[i].push_back({ 0, i * 2 }); // 0초 후 이동
	}

	pq.push(make_pair(0, n)); // 가중치, 시작 위치
	dist[n] = 0;
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

	cout << dist[k];
	
	return 0;
}