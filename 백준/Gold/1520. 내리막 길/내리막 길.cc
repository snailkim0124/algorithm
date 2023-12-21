#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, n;
int visited[505][505];
ll arr[505][505];
ll dp[505][505];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

ll dfs(int y, int x) {
	if (y == m && x == n) return 1;
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	else {
		dp[y][x] = 0;
		visited[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 1 || ny < 1 || nx >= n + 1 || ny >= m + 1) continue;
			if (arr[y][x] > arr[ny][nx]) {
				dp[y][x] += dfs(ny, nx);
			}
		}
		return dp[y][x];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(1, 1);

	return 0;
}