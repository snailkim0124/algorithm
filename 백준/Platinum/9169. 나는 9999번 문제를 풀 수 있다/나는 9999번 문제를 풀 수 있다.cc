#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = 1e18;

struct Edge {
	int to, rev;
	ll cap, flow;
};

int n, m;
int s = 300 + 1;
int t = 300 + 2;
int arr[305];
vector<vector<Edge>> adj(305);
vector<int> level(305), work(305);

void add_edge(int u, int v, ll cap) {
	Edge a = { v, (int)adj[v].size(), cap, 0 };
	Edge b = { u, (int)adj[u].size(), 0 ,0 }; // 역방향 간선
	adj[u].push_back(a);
	adj[v].push_back(b);
}

bool bfs() {
	fill(all(level), -1);
	queue<int> q;
	level[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto& next : adj[now]) {
			if (next.cap - next.flow > 0 && level[next.to] == -1) {
				level[next.to] = level[now] + 1; // source부터 거리 저장
				q.push(next.to);
			}
		}
	}

	return level[t] != -1;
}

ll dfs(ll now, ll flow) {
	if (now == t) return flow;

	for (int &i = work[now]; i < (int)adj[now].size(); i++) {
		Edge &next = adj[now][i];

		if (next.cap - next.flow > 0 && level[next.to] == level[now] + 1) {
			ll tmp = dfs(next.to, min(flow, next.cap - next.flow));
			if (tmp > 0) {
				next.flow += tmp;
				adj[next.to][next.rev].flow -= tmp;
				return tmp;
			}
		}
	}

	return 0;
}

ll dinic() {
	ll sum = 0;
	while (bfs()) {
		fill(all(work), 0);
		// sink로 가는 경로가 없을때까지 반복
		while (ll flow = dfs(s, INF)) {
			sum += flow;
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		level.assign(305, 0);
		work.assign(305, 0);
		adj.assign(305, {});
		s = 300 + 1;
		t = 300 + 2;

		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;

			add_edge(u, v, 1);
			add_edge(v, u, 1);
			
		}

		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) add_edge(s, i, 1);
			else add_edge(i, t, 1);
		}

		cout << dinic() << "\n";


	}

	return 0;
}