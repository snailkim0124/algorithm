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
int s;
int t;
vector<vector<Edge>> adj(405);
vector<int> level(405), work(405), visited(405);

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

void go() {
	visited[s] = 1;
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (next.cap - next.flow > 0 && !visited[next.to]) {
				visited[next.to] = 1;
				q.push(next.to);
			}
		}
	}

	// in은 했는데 out을 못한경우
	for (int i = 1; i <= n; i++) {
		if (visited[i * 2] && !visited[i * 2 + 1]) cout << i << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> s >> t;
	for (int i = 1; i <= n; i++) {
		ll cost;
		cin >> cost;
		add_edge(i * 2, i * 2 + 1, cost);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		add_edge(u * 2 + 1, v * 2, INF);
		add_edge(v * 2 + 1, u * 2, INF);
	}

	s = s * 2;
	t = t * 2 + 1;
	
	dinic();

	go();

	return 0;
}