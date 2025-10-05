#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
vector<int> adj[2005];
int capacity[2005][2005];
int parent[2005];

const int INF = 987654321;

int bfs(int s, int e) {
	memset(parent, -1, sizeof(parent));

	parent[s] = -2;
	queue<pii> q;
	q.push({ s, INF });

	while (!q.empty()) {
		auto [now, flow] = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (parent[next] == -1 && capacity[now][next] > 0) {
				parent[next] = now;
				int new_flow = min(flow, capacity[now][next]);

				if (next == e) return new_flow;
				q.push({ next, new_flow });
			}
		}
	}

	return 0;
}

int maxflow(int s, int e) {
	int flow = 0, new_flow;

	while ((new_flow = bfs(s, e))) {
		flow += new_flow;
		int now = e;
		while (now != s) {
			int prev = parent[now];
			capacity[prev][now] -= new_flow;
			capacity[now][prev] += new_flow;
			now = prev;
		}
	}

	return flow;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	int SRC = n + m + 1; // 시작점
	int P = 0; // 중간점
	int SINK = n + m + 2; // 도착점
	
	// SRC -> 직원
	for (int i = 1; i <= n; i++) {
		capacity[SRC][i] = 1;
		adj[SRC].push_back(i);
		adj[i].push_back(SRC);
	}

	// SRC -> P
	capacity[SRC][0] = k;
	adj[SRC].push_back(0);
	adj[0].push_back(SRC);

	// P -> 직원
	for (int i = 1; i <= n; i++) {
		capacity[0][i] = k;
		adj[0].push_back(i);
		adj[i].push_back(i);
	}

	// 직원 -> 업무
	for (int i = 1; i <= n; i++) {
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++) {
			int num;
			cin >> num;
			capacity[i][n + num] = 1;
			adj[i].push_back(n + num);
			adj[n + num].push_back(i);
		}
	}

	// 업무 -> SINK
	for (int i = 1; i <= m; i++) {
		capacity[n + i][SINK] = 1;
		adj[n + i].push_back(SINK);
		adj[SINK].push_back(n + i);
	}

	cout << maxflow(SRC, SINK) << "\n";

	return 0;
}