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
// 거리
vector<int> c_adj[1005];

// mcmf
vector<vector<Edge>> adj(1005);
vector<ll> dist(1005);
vector<ll> visited(1005), pv(1005), pe(1005);

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

	int tt;
	cin >> tt;

	while (tt--) {
		int n, m;
		cin >> n >> m;

		s = n + n + 1;
		t = s + 1;

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			c_adj[x].push_back(y);
			c_adj[y].push_back(x);
		}

		// 목표 까지 거리 미리 계산
		vector<vector<ll>> c_dist(n + 1, vector<ll>(n + 1, INF));
		for (int i = 1; i <= n; i++) {
			queue<int> q;
			q.push(i);
			c_dist[i][i] = 0;

			while (!q.empty()) {
				int now = q.front();
				q.pop();

				for (auto next : c_adj[now]) {
					if (c_dist[i][next] == INF) {
						c_dist[i][next] = c_dist[i][now] + 1;
						q.push(next);
					}
				}
			}
		}

		vector<int> color, coin;

		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			if (num == 1) color.push_back(i); // 목표 흰색
		}

		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			if (num == 1) coin.push_back(i); // 흰색 코인
		}

		// s -> 흰색 동전
		for (auto i : coin) {
			add_edge(s, i, 1, 0);
		}

		// 흰색 동전 -> 목표 위치
		for (auto i : coin) {
			for (auto j : color) {
				ll cost = c_dist[i][j];
				// cout << i << " : " << j << " : " << cost << "\n";
				add_edge(i, n + j, 1, cost);
			}
		}

		// 목표 위치 -> t
		for (auto j : color) {
			add_edge(n + j, t, 1, 0);
		}

		auto [flow, cost] = mcmf();

		cout << cost << "\n";


		for (int i = 0; i < adj.size(); i++) {
			adj[i].clear();
		}
		for (int i = 0; i <= n; i++) {
			c_adj[i].clear();
		}
		fill(all(pv), 0);
		fill(all(pe), 0);


	}
	

	return 0;
}