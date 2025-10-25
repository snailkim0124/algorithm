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
char arr[105][105];
map<pii, int> mp;
int sy, sx, ey, ex;
int s;
int t;
vector<vector<Edge>> adj(20005);
vector<int> level(20005), work(20005);

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

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'K') {
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == 'H') {
				ey = i;
				ex = j;
			}
			mp[{i, j}] = cnt++; // 격자를 노드로
		}
	}
	
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << mp[{i, j}] << " ";
	//	}
	//	cout << "\n";
	//}

	// K, H 인접할 때
	if (abs(sy - ey) + abs(sx - ex) == 1) {
		cout << -1 << "\n";
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') continue;
			int in = mp[{i, j}] * 2;
			int out = in + 1;

			// K, H는 용량 무제한
			if (arr[i][j] == 'K' || arr[i][j] == 'H') {
				add_edge(in, out, INF);
			}
			else add_edge(in, out, 1);

			// 다음 격자와 연결
			if (i - 1 >= 0 && arr[i - 1][j] != '#') add_edge(out, mp[{i - 1, j}] * 2, INF);
			if (i + 1 < n && arr[i + 1][j] != '#') add_edge(out, mp[{i + 1, j}] * 2, INF);
			if (j - 1 >= 0 && arr[i][j - 1] != '#') add_edge(out, mp[{i, j - 1}] * 2, INF);
			if (j + 1 < m && arr[i][j + 1] != '#') add_edge(out, mp[{i, j + 1}] * 2, INF);
		}
	}

	s = mp[{sy, sx}] * 2;
	t = mp[{ey, ex}] * 2 + 1;

	cout << dinic() << "\n";

	return 0;
}