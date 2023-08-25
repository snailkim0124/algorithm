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

int m, n, h;
int a[104][104][104];
int visited[104][104][104];
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, 1, -1, 0 ,0 };
int dx[6] = { -1, 1, 0, 0, 0, 0};
queue<tuple<int, int, int>> q;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j][k];
				if (a[i][j][k] == 1) {
					q.push({ i,j,k });
				}
				if (a[i][j][k] == 0) {
					visited[i][j][k] = -1;
				}
			}

		}
	}

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (visited[nx][ny][nz] >= 0) continue;
			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx, ny, nz });
		}
	} 

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j][k] == -1) {
					cout << "-1";
					exit(0);
				}
				cnt = max(cnt, visited[i][j][k]);
			}
		}
	}

	cout << cnt;
	return 0;
}