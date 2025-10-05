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

int n;
vector<int> adj[60];
int capacity[60][60];
int parent[60];

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

	cin >> n;

	int SRC = 0;
	int SINK = 25;

	for (int i = 0; i < n; i++) {
		char u, v;
		int w;
		cin >> u >> v >> w;
		if (!capacity[u - 'A'][v - 'A']) {
			adj[u - 'A'].push_back(v - 'A');
			adj[v - 'A'].push_back(u - 'A');
		}
		capacity[u - 'A'][v - 'A'] += w;
		capacity[v - 'A'][u - 'A'] += w;
	}

	cout << maxflow(SRC, SINK) << "\n";

	return 0;
}