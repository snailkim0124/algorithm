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
int visited[205], matched[205];

double dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool dfs(int now) {
	for (auto next : adj[now]) {
		if (visited[next]) continue;
		visited[next] = 1;

		if (matched[next] == -1 || dfs(matched[next])) {
			matched[next] = now;
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> s >> v;

	vector<Point> mouse(n + 1), hole(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> mouse[i].x >> mouse[i].y;
	}

	for (int i = 1; i <= m; i++) {
		cin >> hole[i].x >> hole[i].y;
	}

	// n -> m
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 시간 내에 들어갈 수 있는지 확인
			if (dist(mouse[i], hole[j]) <= (s * v) * (s * v)) {
				adj[i].push_back(j);
			}
		}
	}

	int cnt = 0;
	memset(matched, -1, sizeof(matched));
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) cnt++;
	}

	cout << n - cnt << "\n";


	return 0;
}