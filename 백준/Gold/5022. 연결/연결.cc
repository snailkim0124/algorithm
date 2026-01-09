#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n, m;
pii a1, a2, b1, b2;
pii memo[105][105]; // 역추적용
int fvisited[105][105];
int visited[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res = INF;

int bfs(pii s, pii e, pii s2, pii e2) {
	memset(visited, 0, sizeof(visited));

	queue<pii> q;
	q.push(s);
	visited[s.first][s.second] = 1;

	int dist = 0;
	bool check = false;

	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			auto [y, x] = q.front();
			q.pop();

			if (y == e.first && x == e.second) {
				check = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
				if ((ny == s2.first && nx == s2.second) || (ny == e2.first && nx == e2.second)) continue;
				if (!visited[ny][nx]) {
					visited[ny][nx] = 1;
					memo[ny][nx] = { y, x };
					q.push({ ny, nx });
				}
			}
		}

		if (check) break;
		dist++;
	}

	if (!check) {
		return -1;
	}

	for (pii now = e; ; now = memo[now.first][now.second]) {
		fvisited[now.first][now.second] = 1;
		if (now == s) break;
	}

	return dist;
}

int bfs2(pii s, pii e) {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			// 처음 간곳 표시
			if (fvisited[i][j]) {
				visited[i][j] = 1;
			}
		}
	}

	// 출발지가 이미 막혀 있으면 안됨
	if (visited[s.first][s.second]) {
		return -1;
	}

	queue<pii> q;
	q.push(s);
	visited[s.first][s.second] = 1;

	int dist = 0;
	bool check = false;

	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			auto [y, x] = q.front();
			q.pop();

			if (y == e.first && x == e.second) {
				check = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
				if (!visited[ny][nx]) {
					visited[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}

		if (check) break;
		dist++;
	}

	if (!check) {
		return -1;
	}

	return dist;
}

int go(pii s1, pii e1, pii s2, pii e2) {
	memset(fvisited, 0, sizeof(fvisited));

	int dist1 = bfs(s1, e1, s2, e2);
	if (dist1 == -1) return -1;

	int dist2 = bfs2(s2, e2);
	if (dist2 == -1) return -1;

	return dist1 + dist2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> a1.first >> a1.second;
	cin >> a2.first >> a2.second;
	cin >> b1.first >> b1.second;
	cin >> b2.first >> b2.second;

	// a를 짧게
	int tmp1 = go(a1, a2, b1, b2);
	if (tmp1 != -1) {
		res = min(res, tmp1);
	}

	// b를 짧게
	int tmp2 = go(b1, b2, a1, a2);
	if (tmp2 != -1) {
		res = min(res, tmp2);
	}

	// cout << tmp1 << " : " << tmp2 << "\n";

	if (res == INF) {
		cout << "IMPOSSIBLE\n";
	}
	else cout << res << "\n";

	return 0;
}