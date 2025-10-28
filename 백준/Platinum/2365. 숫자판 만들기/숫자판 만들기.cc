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

int n;
int r[55], c[55];
int ans[55][55], ansmx;
int s;
int t;
vector<vector<Edge>> adj(55);
vector<int> level(20005), work(20005);
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

bool check(int num) {

	s = 0;
	t = 2 * n + 1;
	int N = t + 1;

	level.assign(N, -1);
	work.assign(N, 0);
	adj.clear();
	adj.resize(N);

	// source -> 행
	for (int i = 0; i < n; i++) {
		add_edge(s, i + 1, r[i]);
	}

	// 행 -> 열
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			add_edge(i + 1, n + 1 + j, num);
		}
	}

	// 열 -> sink
	for (int j = 0; j < n; j++) {
		add_edge(n + 1 + j, t, c[j]);
	}

	ll flow = dinic();

	if (mx == flow) {
		int arr[55][55] = { 0 };
		memset(arr, 0, sizeof(arr));
		int tmpmx = -1;

		for (int i = 0; i < n; i++) {
			for (auto& next : adj[i + 1]) {
				if (n + 1 <= next.to && next.to <= n + n) {
					int j = next.to - (n + 1);
					arr[i][j] = next.flow;
					tmpmx = max(tmpmx, arr[i][j]);
				}
			}
		}

		memcpy(ans, arr, sizeof(arr));
		ansmx = tmpmx;

		//cout << "========================\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "========================\n";
	}

	return mx == flow;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> c[i];
		mx += c[i];
	}

	int left = 0;
	int right = mx;
	int res = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ansmx << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	// cout << res << "\n";
	
	return 0;
}