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
char arr[55][55];
vector<vector<Edge>> adj(3005);
vector<ll> dist(3005);
vector<ll> visited(3005), pv(3005), pe(3005);
map<string, ll> score = {
	{"AA", 10}, {"AB", 8}, {"AC", 7}, {"AD", 5}, {"AF", 1},
	{"BA", 8}, {"BB", 6}, {"BC", 4}, {"BD", 3}, {"BF", 1},
	{"CA", 7}, {"CB", 4}, {"CC", 3}, {"CD", 2}, {"CF", 1},
	{"DA", 5}, {"DB", 3}, {"DC", 2}, {"DD", 2}, {"DF", 1},
	{"FA", 1}, {"FB", 1}, {"FC", 1}, {"FD", 1}, {"FF", 0},
};

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

	map<pii, int> mp;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			mp[{i, j}] = cnt++;
		}
	}

	s = cnt + 1;
	t = s + 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				add_edge(s, mp[{i, j}], 1, 0);

				if (i - 1 >= 0) {
					string tmp = "";
					tmp += arr[i][j];
					tmp += arr[i - 1][j];

					add_edge(mp[{i, j}], mp[{i - 1, j}], 1, -score[tmp]);
				}
				if (i + 1 < n) {
					string tmp = "";
					tmp += arr[i][j];
					tmp += arr[i + 1][j];

					add_edge(mp[{i, j}], mp[{i + 1, j}], 1, -score[tmp]);
				}
				if (j - 1 >= 0) {
					string tmp = "";
					tmp += arr[i][j];
					tmp += arr[i][j - 1];

					add_edge(mp[{i, j}], mp[{i, j - 1}], 1, -score[tmp]);
				}
				if (j + 1 < m) {
					string tmp = "";
					tmp += arr[i][j];
					tmp += arr[i][j + 1];

					add_edge(mp[{i, j}], mp[{i, j + 1}], 1, -score[tmp]);
				}

			}
			add_edge(mp[{i, j}], t, 1, 0);
		}
	}

	auto [flow, cost] = mcmf();
	cost = -cost;

	cout << cost << "\n";

	return 0;
}