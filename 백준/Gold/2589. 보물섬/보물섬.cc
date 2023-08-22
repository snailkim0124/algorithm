#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

int n, m, MAX;
char a[55][55];
int visited[55][55];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0 ,1,0 ,-1 };

void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<pair<int,int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] != 0) continue;
			if (a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
			MAX = max(MAX, visited[ny][nx]);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') bfs(i, j);
		}
	}

	cout << MAX - 1;
	return 0;
}