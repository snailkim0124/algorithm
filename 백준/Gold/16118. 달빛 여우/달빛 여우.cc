#include <bits/stdc++.h>

using namespace std;
int n, m;
int dist[4005], dist2[4005][2]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[4005];
int res;

void dijkstra() {
	fill(dist, dist + 4005, INF); // 무한대 값으로 초기화
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1)); // 가중치, 시작 위치
	dist[1] = 0;
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

void dijkstra2() {
	fill(&dist2[0][0], &dist2[0][0] + 4005 * 2, INF); // 무한대 값으로 초기화
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push(make_tuple(0, 1, 0));
	dist2[1][0] = 0;
	while (!pq.empty()) {
		int here_dist, here, cnt;
		tie(here_dist, here, cnt) = pq.top();
		pq.pop();
		if (dist2[here][cnt] != here_dist) continue; // 마지막 정점인가
		int _dist;
		for (pair<int, int> there : adj[here]) {
			if (!cnt) {
				_dist = there.first / 2;
			}
			else {
				_dist = there.first * 2;
			}
			int _there = there.second;
			if (dist2[_there][!cnt] > dist2[here][cnt] + _dist) { // 더 작으면 갱신
				dist2[_there][!cnt] = dist2[here][cnt] + _dist;
				pq.push(make_tuple(dist2[_there][!cnt], _there, !cnt));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back(make_pair(d * 2, b));
		adj[b].push_back(make_pair(d * 2, a));
	}
	dijkstra();
	dijkstra2();

	for (int i = 2; i <= n; i++) {
		int tmp = min(dist2[i][0], dist2[i][1]);
		if (tmp > dist[i]) res++;
	}

	cout << res;
	return 0;
}