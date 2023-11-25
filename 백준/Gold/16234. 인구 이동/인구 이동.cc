#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, l, r;
int arr[55][55];
int visited[55][55];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int sum;
int cnt;

void bfs(int y, int x, vector<pair<int, int>> &v) {
	sum = arr[y][x];
	v.push_back({ y, x });

	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		int _x = q.front().second;
		int _y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!visited[ny][nx] && abs(arr[ny][nx] - arr[_y][_x]) >= l && abs(arr[ny][nx] - arr[_y][_x]) <= r) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
				v.push_back({ ny, nx });
				sum += arr[ny][nx];
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 55 * 55, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					vector<pair<int, int>> v; // 가능한 인구
					bfs(i, j, v);
					if (v.size() == 1) continue;
					for (auto it : v) {
						arr[it.first][it.second] = sum / v.size(); // 인구수 평균
						flag = 1;
					}
				}
			}
		}
		if (!flag) break; // 인구 이동 x
		cnt++;
	}
	

	cout << cnt;

	return 0;
}