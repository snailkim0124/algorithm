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

int arr[55][55];
int s = 50 * 50 + 1;
int t = 50 * 50 + 2;
vector<vector<Edge>> adj(2505);
vector<int> level(2505), work(2505);
int mx = 0;

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

	for (int& i = work[now]; i < (int)adj[now].size(); i++) {
		Edge& next = adj[now][i];

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

	int tt;
	cin >> tt;
	while (tt--) {
		adj.assign(2505, {});
		memset(arr, 0, sizeof(arr));
		level.assign(2505, -1);
		work.assign(2505, 0);

		int n, m;
		cin >> n >> m;
		map<pii, int> mp;
		ll sum = 0;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				mp[{i, j}] = cnt++;
				sum += arr[i][j];
			}
		}

		// 짝수칸 - source, 홀수칸 - sink
		// 짝수칸 - 홀수칸 INF
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 0) {
					add_edge(s, mp[{i, j}], arr[i][j]);

					if (i - 1 >= 0) add_edge(mp[{i, j}], mp[{i - 1, j}], INF);
					if (i + 1 < n) add_edge(mp[{i, j}], mp[{i + 1, j}], INF);
					if (j + 1 < m) add_edge(mp[{i, j}], mp[{i, j + 1}], INF);
					if (j - 1 >= 0) add_edge(mp[{i, j}], mp[{i, j - 1}], INF);

				}
				else {
					add_edge(mp[{i, j}], t, arr[i][j]);
				}
			}
		}

		ll flow = dinic();

		cout << sum - flow << "\n";
	}
	
	return 0;
}