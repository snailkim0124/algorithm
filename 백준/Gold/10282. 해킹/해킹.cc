#include <bits/stdc++.h>

using namespace std;
int t;
int n, d, c;
int dist[10005]; // 가중치
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		fill(dist, dist + 10005, INF); // 무한대 값으로 초기화
		vector<pair<int, int>> adj[10005];
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
		int cnt = 0;
		int res = 0;

		cin >> n >> d >> c; // 컴퓨터 개수, 의존성 개수, 컴퓨터의 번호(시작)

		for (int i = 0; i < d; i++) {
			int a, b, s; // a에서 b까지 s초 걸림
			cin >> a >> b >> s;
			adj[b].push_back(make_pair(s, a));
		}

		pq.push(make_pair(0, c)); // 가중치, 시작 위치
		dist[c] = 0;

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

		for (int i = 1; i <= n; i++) {
			if(dist[i] != INF) {
				res = max(res, dist[i]);
				cnt++;
			}
		}
		cout << cnt << " " << res << "\n";
	}

	return 0;
}