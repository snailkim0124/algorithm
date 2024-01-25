#include <bits/stdc++.h>

using namespace std;
int N, M, K;
int dist[1005]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> distpq[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	fill(dist, dist + 1005, INF); // 무한대 값으로 초기화

	for (int i = 0; i < M; i++) {
		int a, b, c; // a에서 b까지 가중치 c
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
	}

	pq.push(make_pair(0, 1)); // 가중치, 시작 위치
	dist[1] = 0;
	distpq[1].push(0);

	while (!pq.empty()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();

		for (pair<int, int> there : adj[here]) {
			int _dist = there.first + here_dist;
			int _there = there.second;

			if (distpq[_there].size() < K) {
				distpq[_there].push(_dist);
				pq.push(make_pair(_dist, _there));
			}
			else if (distpq[_there].top() > _dist) {
				// 가장 큰 값 없애기
				distpq[_there].pop();
				distpq[_there].push(_dist);
				pq.push(make_pair(_dist, _there));
			}
			
		}
	}

	for (int i = 1; i <= N; i++) {
		if (distpq[i].size() == K) {
			cout << distpq[i].top() << "\n";
		}
		else cout << -1 << "\n";
	}

	return 0;
}