#include <bits/stdc++.h>

using namespace std;
int n;
int arr[130][130];
int visited[130][130];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int t = 1; ; t++) {
		fill(&arr[0][0], &arr[0][0] + 130 * 130, 0);
		fill(&visited[0][0], &visited[0][0] + 130 * 130, INF);

		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
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

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (visited[nx][ny] > visited[x][y] + arr[nx][ny]) {
					visited[nx][ny] = visited[x][y] + arr[nx][ny];
					q.push({ nx, ny });
				}
			}
		}

		cout << "Problem " << t << ": " << visited[n - 1][n - 1] << "\n";
	}
	
	

	return 0;
}