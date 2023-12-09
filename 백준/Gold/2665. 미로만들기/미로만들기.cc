#include <bits/stdc++.h>

using namespace std;
int n;
int arr[55][55];
int visited[55][55];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
const int INF = 987654321;

void bfs() {
	fill(&visited[0][0], &visited[0][0] + 55 * 55, INF);
	queue<pair<int, int>> q;
	visited[0][0] = 0;
	q.push({ 0,0 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[ny][nx] == 1) {
				if (visited[ny][nx] > visited[y][x]) {
					visited[ny][nx] = visited[y][x];
					q.push({ ny, nx });
				}
			}
			else {
				if (visited[ny][nx] > visited[y][x] + 1) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}

}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs();

	printf("%d", visited[n - 1][n - 1]);


	
	return 0;
}