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
vector<int> adj[805];
int capacity[805][805];
int parent[805];

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
	for (int i = 1; i <= n; i++) {
		int in = i * 2;
		int out = i * 2 + 1;
		adj[in].push_back(out);
		adj[out].push_back(in);
		capacity[in][out] = 1;
	}

	for (int i = 0; i < p; i++) {
		int u, v;
		cin >> u >> v;

		int u_in = u * 2;
		int v_in = v * 2;
		int u_out = u * 2 + 1;
		int v_out = v * 2 + 1;

		adj[u_out].push_back(v_in);
		adj[v_in].push_back(u_out);
		adj[v_out].push_back(u_in);
		adj[u_in].push_back(v_out);
		
		capacity[u_out][v_in] = INF;
		capacity[v_out][u_in] = INF;
	}

	int SRC = 1 * 2 + 1;
	int SINK = 2 * 2;
	cout << maxflow(SRC, SINK) << "\n";

	return 0;
}