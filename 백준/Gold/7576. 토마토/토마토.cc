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

int m, n;
int a[1004][1004];
int visited[1004][1004];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0 ,-1 };
queue<pair<int, int>> q;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (a[nx][ny] == 0) {
				a[nx][ny] = a[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	} 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				cout << "-1";
				exit(0);
			}
			cnt = max(cnt, a[i][j]);
		}
	}

	cout << cnt - 1;
	return 0;
}