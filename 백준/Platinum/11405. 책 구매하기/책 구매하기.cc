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
vector<int> a(105), b(105);
vector<vector<Edge>> adj(205);
vector<ll> dist(205);
vector<ll> visited(205), pv(205), pe(205);

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

	for (int j = 1; j <= n; j++) {
		cin >> a[j];
		add_edge(j + m, t, a[j], 0);
	}

	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		add_edge(s, i, b[i], 0);
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int c;
			cin >> c;
			add_edge(i, j + m, b[i], c);
		}
	}

	auto [flow, cost] = mcmf();

	cout << cost << "\n";
	

	return 0;
}