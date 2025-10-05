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

int n, p;
vector<int> adj[405];
int capacity[405][405];
int parent[405];

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

	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[u][v]++;
	}
	
	cout << maxflow(1, 2) << "\n";

	return 0;
}