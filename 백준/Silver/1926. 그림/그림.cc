#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[505][505];
int visited[505][505];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt;
int mx;

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
			if (arr[i][j] == 0 || visited[i][j]) continue;
			cnt++;
			queue<pair<int, int>> q;
			visited[i][j] = 1;
			q.push({ i, j });
			int picture = 0;
			while (!q.empty()) {
				picture++;
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int ii = 0; ii < 4; ii++) {
					int nx = x + dx[ii];
					int ny = y + dy[ii];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (visited[nx][ny] || arr[nx][ny] != 1) continue;
					visited[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			mx = max(mx, picture);
		}
	}

	cout << cnt << "\n" << mx;
	return 0;
}