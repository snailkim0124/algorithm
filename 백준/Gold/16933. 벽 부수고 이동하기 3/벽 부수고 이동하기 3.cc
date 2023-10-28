#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int arr[1005][1005];
int visited[1005][1005][15][2]; // [][][벽을 부순 횟수][낮,밤]
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans;

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q; // { {x, y}, {벽부순횟수, 낮}}
	visited[1][1][0][1] = 1;
	q.push({ { 1, 1 }, {0, 1} });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int sun = q.front().second.second;
		q.pop();

		if (x == n && y == m) {
			return visited[x][y][wall][sun];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= m + 1 || visited[nx][ny][wall][!sun]) continue;

			if (arr[nx][ny] == 1 && wall + 1 <= k && sun) {
				if (visited[nx][ny][wall + 1][!sun]) continue;
				visited[nx][ny][wall + 1][!sun] = visited[x][y][wall][sun] + 1;
				q.push({ { nx, ny }, {wall + 1, !sun } });
			}
			if (arr[nx][ny] == 0 && !visited[nx][ny][wall][!sun]) {
				visited[nx][ny][wall][!sun] = visited[x][y][wall][sun] + 1;
				q.push({ { nx, ny }, {wall, !sun} });
			}

		}
		if (!sun && !visited[x][y][wall][!sun]) {
			visited[x][y][wall][!sun] = visited[x][y][wall][sun] + 1;
			q.push({ {x, y}, {wall, !sun} });
		}
	}

	return -1;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	ans = bfs();
	printf("%d", ans);

	return 0;
}