#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[55][55];
int visited[55][55];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
const int INF = 987654321;
int mxdist = -1, res = -1;

void bfs(int starty, int startx) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	q.push({ starty, startx });
	visited[starty][startx] = 1;

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		if (visited[y][x] > mxdist) {
			mxdist = visited[y][x];
			res = arr[starty][startx] + arr[y][x];
		}
		else if (visited[y][x] == mxdist) {
			res = max(res, arr[starty][startx] + arr[y][x]);
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (arr[ny][nx] != 0) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
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
			if (arr[i][j] != 0) bfs(i, j);
		}
	}

	cout << res;

	return 0;
}