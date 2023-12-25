#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int R, C, D;
int arr[55][55];
int visited[55][55];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int cnt;

void dfs(int y, int x, int d) {
	if(!visited[y][x]) cnt++;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nd = (d + 3 - i) % 4; // 반시계 
		int ny = y + dy[nd];
		int nx = x + dx[nd];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n || arr[ny][nx] == 1) continue;
		if (!visited[ny][nx]) {
			dfs(ny, nx, nd);
		}
	}

	int nd = (d + 2) % 4; // 후진
	int ny = y + dy[nd];
	int nx = x + dx[nd];

	if (arr[ny][nx] == 1) {
		cout << cnt;
		exit(0);
	}
	dfs(ny, nx, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> R >> C >> D;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(R, C, D);


	return 0;
}