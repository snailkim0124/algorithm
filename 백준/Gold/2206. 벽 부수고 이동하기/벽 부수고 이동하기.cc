#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[1005][1005];
int visited[1005][1005][2]; // [][][벽을 부순 횟수]
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans;

int bfs() {
	queue<pair<pair<int, int>, int>> q; // { {x, y}, 벽부순횟수}
	visited[1][1][0] = 1;
	q.push({ { 1, 1 }, 1 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second;
		q.pop();

		if (x == n && y == m) {
			return visited[x][y][wall] + 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= m + 1) continue;

			if (arr[nx][ny] == 1 && wall) {
				visited[nx][ny][wall - 1] = visited[x][y][wall] + 1;
				q.push({ { nx, ny }, wall - 1 });
			}
			else if (arr[nx][ny] == 0 && !visited[nx][ny][wall]) {
				visited[nx][ny][wall] = visited[x][y][wall] + 1;
				q.push({ { nx, ny }, wall });
			}

		}
	}

	return -1;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	ans = bfs();
	printf("%d", ans);

	return 0;
}