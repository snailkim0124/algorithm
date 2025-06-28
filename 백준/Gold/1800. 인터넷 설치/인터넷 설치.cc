#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, p, k;
int res = -1;
int mx = -1;
const int INF = 987654321;
vector<pii> adj[10005];

bool check(int cost) {
	int cnt = 0;
	int dist[10005] = { 0 }; // 간선 개수
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill(dist, dist + 10005, INF);

	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;
		for (pii there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			int ddist = here_dist + (_dist > cost);

			if (dist[_there] > ddist) {
				dist[_there] = ddist;
				pq.push({ dist[_there], _there });
			}
		}
	}

	return dist[n] <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> p >> k;

	for (int i = 0; i < p; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
		mx = max(mx, w);
	}


	int left = 0;
	int right = mx;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << res;

	return 0;
}