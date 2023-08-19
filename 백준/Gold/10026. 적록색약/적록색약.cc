#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, cnt, cnt2;

char a[105][105];
char greenred[105][105];
int visited[105][105];
int visited2[105][105];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visited[nx][ny] == 1) continue;
		if (a[x][y] == a[nx][ny]) {
			dfs(nx, ny);
		}
	}

}

void dfs2(int x, int y) {
	visited2[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visited2[nx][ny] == 1) continue;
		if (greenred[x][y] == greenred[nx][ny]) {
			dfs2(nx, ny);
		}
	}

}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			greenred[i][j] = a[i][j];
			if (greenred[i][j] == 'G') {
				greenred[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited2[i][j] == 0) {
				dfs2(i, j);
				cnt2++;
			}
		}
	}

	printf("%d %d", cnt, cnt2);
	return 0;
}