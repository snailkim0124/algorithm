#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[105][75];
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int visited[105][75];
int cnt;
bool check;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (arr[y][x] < arr[ny][nx]) { // 봉우리가 갱신, 더 큰게 있음
			check = false;
		}
		if (!visited[ny][nx] && arr[y][x] == arr[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check = true;
			if (!visited[i][j]) {
				dfs(i, j);
				if (check) cnt++;
			}
		}
	}
	
	cout << cnt;

	return 0;
}