#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int h, w, n;
char arr[1005][1005];
int visited[1005][1005];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int cnt;
int lasty, lastx;
int res;

void bfs(int starty, int startx, int target) {
	queue<pair<int, int>> q;
	q.push({ starty, startx });
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		if (arr[y][x] - '0' == target) {
			arr[y][x] = '.';
			lasty = y;
			lastx = x;
			res += visited[y][x];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || ny >= h || nx >= w || arr[ny][nx] == 'X' || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int startx, starty;
	cin >> h >> w >> n;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				starty = i;
				startx = j;
				arr[i][j] = '.';
			}
		}
	}

	lasty = starty;
	lastx = startx;

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(lasty, lastx, i);
	}

	cout << res;

	return 0;
}