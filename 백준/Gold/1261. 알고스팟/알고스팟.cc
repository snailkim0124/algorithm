#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[105][105];
int visited[105][105];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
const int INF = 987654321;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	fill(&arr[0][0], &arr[0][0] + 105 * 105, 0);
	fill(&visited[0][0], &visited[0][0] + 105 * 105, INF);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = arr[0][0];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (visited[nx][ny] > visited[x][y] + arr[nx][ny]) {
				visited[nx][ny] = visited[x][y] + arr[nx][ny];
				q.push({ nx, ny });
			}
		}
	}

	printf("%d", visited[m - 1][n - 1]);
	
	

	return 0;
}