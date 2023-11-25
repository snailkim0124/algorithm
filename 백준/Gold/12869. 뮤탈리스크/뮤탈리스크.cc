#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[5];
int visited[65][65][65];
int dp[65][65][65];
queue<tuple<int, int, int>> q;
int alist[6][3] = { // 모든 경우의 수
	{9,3,1},
	{9,1,3},
	{3,1,9},
	{3,9,1},
	{1,3,9},
	{1,9,3}
};


int bfs(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int nx = max(0, x - alist[i][0]);
			int ny = max(0, y - alist[i][1]);
			int nz = max(0, z - alist[i][2]);
			if (!visited[nx][ny][nz]) {
				visited[nx][ny][nz] = visited[x][y][z] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}
	return visited[0][0][0] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << bfs(arr[0], arr[1], arr[2]);

	return 0;
}