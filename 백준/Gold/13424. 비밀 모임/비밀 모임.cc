#include <bits/stdc++.h>

using namespace std;
int t;
int N, M;
int k;
int dist[105]; // 가중치
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		vector<pair<int, int>> adj[105];
		int arr[105] = { 0 };

		cin >> N >> M; // 방의 개수, 비밀통로 개수

		for (int i = 0; i < M; i++) {
			int a, b, c; // a에서 b까지 c만큼 길이
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(c, b));
			adj[b].push_back(make_pair(c, a));
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			fill(dist, dist + 105, INF); // 무한대 값으로 초기화
			pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
			int start;
			cin >> start; // 친구들 현재 위치

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

			for (int j = 1; j <= N; j++) { // 총합 거리 계산
				arr[j] += dist[j];
			}
		}

		int ans_there = arr[1];
		int res = 1; // 가장 작은 방 번호

		for (int i = 2; i <= N; i++) {
			if (arr[i] < ans_there) {
				ans_there = arr[i];
				res = i;
			}
		}
		cout << res << "\n";
	}

	return 0;
}