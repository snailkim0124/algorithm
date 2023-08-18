#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
int a[504][504];
int visited[504][504];
int dy[4] = { -1,0,1 ,0 };
int dx[4] = { 0,1,0,-1 };
int other;
int MAX;

void dfs(int x, int y, int depth, int score) {
	if (depth == 3) {
		MAX = max(MAX, score);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || ny >= m || nx >= n) continue;
		if (visited[nx][ny] == 1) continue;
		visited[nx][ny] = 1;
		dfs(nx, ny, depth + 1, score + a[nx][ny]);
		visited[nx][ny] = 0;
	}
}

void count(int x, int y) {
	if (y + 1 < m && x + 2 < n)
		other = max(other, a[x][y] + a[x+1][y] + a[x + 2][y] + a[x + 1][y + 1]);

	if (y + 2 < m && x + 1 < n)
		other = max(other, a[x][y] + a[x][y+1] + a[x + 1][y + 1] + a[x][y + 2]);

	if (y - 1 >= 0 && x + 2 < n)
		other = max(other, a[x][y] + a[x+1][y] + a[x + 2][y] + a[x + 1][y - 1]);

	if (y + 2 < m && x - 1 >= 0)
		other = max(other, a[x][y] + a[x][y+1] + a[x- 1][y+1] + a[x][y + 2]);
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
			visited[i][j] = 1;
			dfs(i, j, 0, a[i][j]);
			count(i, j);
			visited[i][j] = 0;
		}
	}

	cout << max(other, MAX);
	return 0;
}