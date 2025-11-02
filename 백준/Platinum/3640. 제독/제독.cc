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
vector<vector<Edge>> adj;
vector<ll> dist;
vector<ll> visited, pv, pe;

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

	int v, e;
	while (cin >> v >> e) {
		adj.assign(2 * v + 5, {});
		pv.assign(2 * v + 5, 0);
		pe.assign(2 * v + 5, 0);
		dist.assign(2 * v + 5, INF);
		visited.assign(2 * v + 5, 0);

		// 경로 수 가 2개 가능
		add_edge(1 * 2, 1 * 2 + 1, 2, 0);
		add_edge(v * 2, v * 2 + 1, 2, 0);

		// 각 노드 in-out 설정
		for (int i = 2; i < v; i++) {
			add_edge(i * 2, i * 2 + 1, 1, 0);
		}

		while (e--) {
			int a, b, c;
			cin >> a >> b >> c;
			add_edge(a * 2 + 1, b * 2, 1, c);
		}

		s = 1 * 2;
		t = 2 * v + 1;

		auto [flow, cost] = mcmf();

		cout << cost << "\n";
	}


	return 0;
}