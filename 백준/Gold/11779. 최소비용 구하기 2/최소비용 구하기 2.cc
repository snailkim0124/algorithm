#include <bits/stdc++.h>

using namespace std;

int N, M;
int dist[1005]; // 가중치
const int INF = 987654321;
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int start, _end;
int arr[100005];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(dist, dist + 1005, INF); // 무한대 값으로 초기화
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}
	cin >> start >> _end; // 시작, 끝

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue;
		for (pair<int, int> there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			if (dist[_there] > dist[here] + _dist) {
				arr[_there] = here;
				dist[_there] = dist[here] + _dist;
				pq.push(make_pair(dist[_there], _there));
			}
		}
	}

	cout << dist[_end] << "\n";
	for (int i = _end; i != start; i = arr[i]) {
		v.push_back(i);
	}

	v.push_back(start);
	reverse(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto it : v) cout << it << " ";

	return 0;
}