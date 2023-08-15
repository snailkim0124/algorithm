#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;
int n;
int a[30][30];
int visited[30][30];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,1,0,-1 };
int cnt;
vector<int> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] == 1 && !visited[ny][nx]) {
			cnt++;
			dfs(ny, nx);

		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	
	sort(v.begin(), v.end());
	printf("%d\n", (int)v.size());
	for (auto it : v) printf("%d\n", it);

	return 0;
}