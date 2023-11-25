#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r, c;
char arr[25][25];
int visited[27]; // 알파벳
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int res;

void dfs(int y, int x, int cnt) {
	res = max(res, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		int next = (int)(arr[ny][nx] - 'A');

		if (!visited[next]) { // 백트래킹
			visited[next] = 1;
			dfs(ny, nx, cnt + 1);
			visited[next] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	visited[(int)(arr[0][0] - 'A')] = 1;
	dfs(0, 0, 1);

	cout << res;

	return 0;
}