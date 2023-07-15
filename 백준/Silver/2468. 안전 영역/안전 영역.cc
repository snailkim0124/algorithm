#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n;
int max_value =1;
int a[104][104];
int visited[104][104];
int dy[4] = { -1,0,1, 0 };
int dx[4] = { 0,1,0,-1 };

void dfs(int y, int x, int depth) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] > depth && !visited[ny][nx]) {
			dfs(ny, nx, depth);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int depth = 1; depth < 101; depth++) {
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > depth && !visited[i][j]) {
					dfs(i, j, depth);
					cnt++;
				}
			}
		}
		max_value = max(max_value, cnt);
	}

	cout << max_value;
	return 0;
}