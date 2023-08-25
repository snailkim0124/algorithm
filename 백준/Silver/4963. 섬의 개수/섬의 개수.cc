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

int w, h;
int a[54][54];
int visited[54][54];
int dy[8] = { -1,1,0,0,-1,1,-1,1 };
int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int cnt = 0;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if (a[ny][nx] != 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cnt = 0;
		fill(&a[0][0], &a[0][0] + 54 * 54, 0);
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] != 0 && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}