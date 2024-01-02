#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[55][55];
int visited[55][55];
const int dy[] = { -1,-1,-1,0,0,1,1,1 };
const int dx[] = { -1,0,1,-1,1,-1,0,1 };
queue<pair<int, int>> q;
int mx;

void bfs() {
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		visited[y][x] = 1;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				arr[ny][nx] = arr[y][x] + 1;
				mx = max(mx, arr[ny][nx]);
				q.push({ ny, nx });
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
			if (arr[i][j] == 1) {
				q.push({ i, j });
				arr[i][j] = 0;
				visited[i][j] = 1;
			}
		}
	}

	bfs();

	cout << mx;

	
	return 0;
}