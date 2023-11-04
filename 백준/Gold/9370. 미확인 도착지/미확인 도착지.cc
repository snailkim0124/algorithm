#include <bits/stdc++.h>

using namespace std;
int T;
int n, m, t;
int s, g, h;
int dist[2005]; // 가중치
const int INF = 987654320;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<pair<int, int>> adj[2005];
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		fill(dist, dist + 2005, INF); // 무한대 값으로 초기화

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			d *= 2; // 짝수로 만들기
			if ((a == g && b == h) || (a == h && b == g)) { // 홀수로 만들기
				d--;
			}
			adj[a].push_back(make_pair(d, b));
			adj[b].push_back(make_pair(d, a));
		}

		int arr[105] = { 0 };
		for (int i = 0; i < t; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + t);

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

		for (int i = 0; i < t; i++) {
			if (dist[arr[i]] % 2 == 1) {
				cout << arr[i] << " ";
			}
		}

		cout << "\n";
	}
	

	return 0;
}