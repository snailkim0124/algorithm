#include <bits/stdc++.h>

using namespace std;

int N, M, X;
int dist[1005]; // 가중치
int ans_dist[1005]; // 돌아오는 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}


	for (int i = 1; i <= N; i++) { // X로 가기
		fill(dist, dist + 1005, INF);
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();

		pq.push({ 0, i });
		dist[i] = 0;

		while (!pq.empty()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if (dist[here] != here_dist) continue;
			for (pair<int, int> there : adj[here]) {
				int _dist = there.first;
				int _there = there.second;
				if (dist[_there] > dist[here] + _dist) {
					dist[_there] = dist[here] + _dist;
					pq.push(make_pair(dist[_there], _there));
				}
			}
		}
		ans_dist[i] = dist[X]; // i->X 저장
	}

	for (int i = 1; i <= N; i++) { // X에서 다시 돌아가기
		fill(dist, dist + 1005, INF);
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();

		pq.push({ 0, X });
		dist[X] = 0;

		while (!pq.empty()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if (dist[here] != here_dist) continue;
			for (pair<int, int> there : adj[here]) {
				int _dist = there.first;
				int _there = there.second;
				if (dist[_there] > dist[here] + _dist) {
					dist[_there] = dist[here] + _dist;
					pq.push(make_pair(dist[_there], _there));
				}
			}
		}
		ans_dist[i] += dist[i];  // X->i 저장
	}
	
	for (int i = 1; i <= N; i++) {
		res = max(res, ans_dist[i]);
	}

	cout << res;
	return 0;
}