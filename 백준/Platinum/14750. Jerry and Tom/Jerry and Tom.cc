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
	ll x, y;
};

int n, k, h, m;
vector<int> adj[305];
int capacity[305][305];
int parent[305];
const int INF = 987654321;

ll ccw(Point a, Point b, Point c) {
	ll res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}

bool iscross(Point a, Point b, Point c, Point d) {
	if (ccw(c, d, a) == 0) return false;
	if (ccw(c, d, a) * ccw(c, d, b) > 0) return false;
	if (ccw(a, b, c) * ccw(a, b, d) > 0) return false;
	return true;
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

	cin >> n >> k >> h >> m;

	int SRC = h + m + 1;
	int SINK = h + m + 2;

	vector<Point> house(n), hole(h + 1), mouse(m + 1);

	for (int i = 0; i < n; i++) {
		cin >> house[i].x >> house[i].y;
	}

	for (int i = 1; i <= h; i++) {
		cin >> hole[i].x >> hole[i].y;
	}

	for (int i = 1; i <= m; i++) {
		cin >> mouse[i].x >> mouse[i].y;
	}

	// SRC -> h
	for (int i = 1; i <= h; i++) {
		capacity[SRC][i] = k;
		adj[SRC].push_back(i);
		adj[i].push_back(SRC);
	}

	// h -> m
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= m; j++) {
			bool flag = true;
			// 집이랑 교차하는지 검증
			for (int k = 0; k < n; k++) {
				if (iscross(hole[i], mouse[j], house[k], house[(k + 1) % n])) {
					flag = false;
					break;
				}
			}

			if (flag) {
				// cout << mouse[i].x << " " << mouse[i].y << " : " << hole[j].x << " " << hole[j].y;
				capacity[i][h + j] = 1;
				adj[i].push_back(h + j);
				adj[h + j].push_back(i);
			}
		}
	}

	// m -> SINK
	for (int i = 1; i <= m; i++) {
		capacity[h + i][SINK] = 1;
		adj[h + i].push_back(SINK);
		adj[SINK].push_back(h + i);
	}

	cout << (maxflow(SRC, SINK) == m ? "Possible" : "Impossible") << "\n";

	return 0;
}