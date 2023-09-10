#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int n, m;
int arr[1005][1005];
int visited[1005][1005];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] == 0 && arr[nx][ny] != 0) {
				arr[nx][ny] = arr[x][y] + 1;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j }); // 목표지점 등록
				visited[i][j] = 1;
				arr[i][j] = 0; // ***초기화***
			}
			else if (arr[i][j] == 0) {
				visited[i][j] = 1;
			}
		}
	}
	
	bfs(); //bfs 돌리기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) cout << -1 << " "; // 방문 안했을 때
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}