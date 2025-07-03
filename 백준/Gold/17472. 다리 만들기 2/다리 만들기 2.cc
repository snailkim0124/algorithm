#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
} EDGE;

int n, m;
int arr[15][15];
int visited[15][15];
int island[10];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int mn = 987654321;
int cnt = 0;
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;
int res;

void bfs(int _y, int _x, int num) {
	visited[_y][_x] = num;
	queue<pii> q;
	q.push({ _y, _x });

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 1 && !visited[ny][nx]) {
				visited[ny][nx] = num;
				q.push({ ny, nx });
			}
		}
	}
}

void make_bridge(int y, int x, int dir) {
	int sum = 0;
	int first_island = visited[y][x];
	int ny = y;
	int nx = x;

	while (1) {
		// 일직선으로 이동
		ny += dy[dir];
		nx += dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == first_island) return;
		if (!visited[ny][nx]) sum++;
		else {
			if (sum >= 2) pq.push({ first_island, visited[ny][nx], sum });
			// cout << "make_bridge : " << first_island << " : " << visited[ny][nx] << " : " << sum << "\n";
			return;
		}
	}

}

int findParent(int a) {
	if (a == island[a]) return a;
	else return island[a] = findParent(island[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		island[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				bfs(i, j, ++cnt);
			}
		}
	}

	//cout << "cnt : " << cnt;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << visited[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//exit(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int dir = 0; dir < 4; dir++) {
				if (visited[i][j]) {
					// cout << i << " : " << j << "\n";
					make_bridge(i, j, dir);
				}
			}
		}
	}

	for (int i = 1; i <= 6; i++) {
		island[i] = i;
	}

	//while (!pq.empty()) {
	//	EDGE now = pq.top();
	//	pq.pop();

	//	cout << now.s << " : " << now.e << " : " << now.v << "\n";
	//}
	//exit(0);

	int useEdge = 0; // 연결된 섬 개수 확인
	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) {
			unionParent(now.s, now.e);
			res += now.v;
			useEdge++;
		}
	}

	// cout << "cnt : " << cnt << "\n";
	// cout << "useEdge : " << useEdge << "\n";

	if (useEdge == cnt - 1) cout << res;
	else cout << -1;

	return 0;
}