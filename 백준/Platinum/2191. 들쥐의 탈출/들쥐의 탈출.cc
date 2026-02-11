#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Point {
	double x, y;
};

int n, m, s, v;
vector<int> adj[205];
int capacity[205][205];
int parent[205];
const int INF = 987654321;

double dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int bfs(int s, int e) {
	memset(parent, -1, sizeof(parent));

	parent[s] = -2;
	queue<pii> q;
	q.push({ s, INF });

	while (!q.empty()) {
		auto [now, flow] = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (parent[next] == -1 && capacity[now][next] > 0) {
				parent[next] = now;
				int new_flow = min(flow, capacity[now][next]);

				if (next == e) return new_flow;
				q.push({ next, new_flow });
			}
		}
	}

	return 0;
}

int maxflow(int s, int e) {
	int flow = 0, new_flow;

	while ((new_flow = bfs(s, e))) {
		flow += new_flow;
		int now = e;
		while (now != s) {
			int prev = parent[now];
			capacity[prev][now] -= new_flow;
			capacity[now][prev] += new_flow;
			now = prev;
		}
	}

	return flow;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> s >> v;

	int SRC = n + m + 1;
	int SINK = SRC + 1;

	vector<Point> mouse(n + 1), hole(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> mouse[i].x >> mouse[i].y;
	}

	for (int i = 1; i <= m; i++) {
		cin >> hole[i].x >> hole[i].y;
	}

	// SRC -> m
	for (int i = 1; i <= m; i++) {
		capacity[SRC][i] = 1; // 한마리씩 들어갈 수 있음
		adj[SRC].push_back(i);
		adj[i].push_back(SRC);
	}

	// m -> n
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// 시간 내에 들어갈 수 있는지 확인
			if (dist(hole[i], mouse[j]) <= (s * v) * (s * v)) {
				capacity[i][m + j] = 1;
				adj[i].push_back(m + j);
				adj[m + j].push_back(i);
			}
		}
	}

	// n -> SINK
	for (int j = 1; j <= n; j++) {
		capacity[m + j][SINK] = 1;
		adj[m + j].push_back(SINK);
		adj[SINK].push_back(m + j);
	}

	cout << n - maxflow(SRC, SINK) << "\n";


	return 0;
}