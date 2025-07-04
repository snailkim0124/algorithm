#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[105][105];
int visited[105][105];
int visited2[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int cnt = 0;
int res = 987654321;

typedef struct BRIDGE {
	int y, x, w;
}BRIDGE;

void bfs(int _y, int _x, int num) {
	visited[_y][_x] = num;
	queue<pii> q;
	q.push({ _y, _x });

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!visited[ny][nx] && arr[ny][nx] == 1) {
				visited[ny][nx] = num;
				q.push({ ny, nx });
			}
		}

	}
}

int make_bridge(int num) {
	queue<BRIDGE> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == num) {
				visited2[i][j] = 1;
				q.push({ i, j, 0 });
			}
		}
	}

	while (!q.empty()) {
		BRIDGE now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[ny][nx] != 0 && visited[ny][nx] != num) {
				return now.w;
			}
			if (!visited2[ny][nx]) {
				visited2[ny][nx] = 1;
				q.push({ ny, nx, now.w + 1 });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				bfs(i, j, ++cnt);
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		memset(visited2, 0, sizeof(visited2));
		res = min(res, make_bridge(i));
	}

	cout << res;
	
	return 0;
}