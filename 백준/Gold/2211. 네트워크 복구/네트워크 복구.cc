#include <bits/stdc++.h>

using namespace std;
int N, M;
int dist[1005]; // 가중치
vector<pair<int, int>> adj[1005];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int arr[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M; // 컴퓨터의 번호, 회선 개수

	for (int i = 0; i < M; i++) {
		int a, b, c; // a에서 b까지 c초 걸림
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	for (int i = 1; i <= N; i++) {
		fill(dist, dist + 1005, INF); // 무한대 값으로 초기화
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
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
					arr[_there] = here;
				}
			}
		}
	}
	
	cout << N - 1 << "\n";
	for (int i = 2; i <= N; i++) {
		cout << arr[i] << " " << i << "\n";
	}
	return 0;
}