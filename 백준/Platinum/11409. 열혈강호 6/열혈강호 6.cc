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
	ll cap, cost;
};

int s, t;
vector<vector<Edge>> adj(805);
vector<ll> dist(805);
vector<ll> visited(805), pv(805), pe(805);

void add_edge(int u, int v, ll cap, ll cost) {
	Edge a = { v, (int)adj[v].size(), cap, cost };
	Edge b = { u, (int)adj[u].size(), 0, -cost }; // 역방향 간선
	adj[u].push_back(a);
	adj[v].push_back(b);
}

bool spfa() {
	fill(all(dist), INF);
	fill(all(visited), 0);

	queue<int> q;
	dist[s] = 0;
	visited[s] = 1;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		visited[now] = 0;

		for (int i = 0; i < adj[now].size(); i++) {
			Edge& next = adj[now][i];
			// 다익스트라 방식
			if (next.cap > 0 && dist[next.to] > dist[now] + next.cost) {
				dist[next.to] = dist[now] + next.cost;
				pv[next.to] = now; // 부모 노드 추가
				pe[next.to] = i; // 부모 간선 추가

				if (!visited[next.to]) {
					visited[next.to] = 1;
					q.push(next.to);
				}
			}

		}
	}


	return dist[t] < INF;
}

pll mcmf() {
	ll flow = 0, cost = 0;

	while (spfa()) {
		ll tmp = INF;

		for (int now = t; now != s; now = pv[now]) {
			auto& next = adj[pv[now]][pe[now]];
			tmp = min(tmp, next.cap);
		}

		for (int now = t; now != s; now = pv[now]) {
			auto& next = adj[pv[now]][pe[now]];
			next.cap -= tmp;
			adj[now][next.rev].cap += tmp;
			cost += tmp * next.cost;
		}

		flow += tmp;
	}

	return { flow, cost };
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	s = n + m + 1;
	t = s + 1;

	// s -> 직원
	for (int i = 1; i <= n; i++) {
		add_edge(s, i, 1, 0);
	}

	// 직원 -> 일
	for (int i = 1; i <= n; i++) {
		int sz;
		cin >> sz;
		while (sz--) {
			int v;
			ll cost;
			cin >> v >> cost;
			add_edge(i, n + v, 1, -cost); // 부호 바꾸기
		}
	}

	// 일 -> t
	for (int i = 1; i <= m; i++) {
		add_edge(n + i, t, 1, 0);
	}

	auto [flow, cost] = mcmf();
	cost = -cost; // 부호 바꾸기

	cout << flow << "\n" << cost << "\n";

	return 0;
}