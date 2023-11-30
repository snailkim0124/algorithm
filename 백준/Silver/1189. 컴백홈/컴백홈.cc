#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, c, k;
char arr[10][10];
int visited[10][10];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

int dfs(int y, int x) {
	if (y == 0 && x == c - 1) {
		if (k == visited[y][x]) {
			return 1;
		}
		return 0;
	}

	int res = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (!visited[ny][nx] && arr[ny][nx] != 'T') {
			visited[ny][nx] = visited[y][x] + 1;
			res += dfs(ny, nx);
			visited[ny][nx] = 0;
		}
	}

	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	visited[r - 1][0] = 1;
	cout << dfs(r - 1, 0);
	

	return 0;
}