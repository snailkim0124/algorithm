#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct ROBOT {
	int y, x, dir, cnt;
};

const int INF = 987654321;
int m, n;
int arr[105][105];
int visited[105][105][5];
const int dy[5] = { 0,0,0,1,-1 };
const int dx[5] = { 0,1,-1,0,0 };
int sy, sx, sdir, ey, ex, edir;

bool check(int y, int x) {
	return (1 <= y && y <= m && 1 <= x && x <= n && arr[y][x] == 0);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> sy >> sx >> sdir;
	cin >> ey >> ex >> edir;

	

	fill(&visited[0][0][0], &visited[0][0][0] + 105 * 105 * 5, INF);
	queue<tii> q;
	q.push({ sy, sx, sdir });
	visited[sy][sx][sdir] = 0;

	while (!q.empty()) {
		auto [y, x, dir] = q.front();
		q.pop();

		if (y == ey && x == ex && dir == edir) {
			cout << visited[y][x][dir] << "\n";
			break;
		}

		// 1. 직진 (가장 멀리 가기)
		for (int k = 1; k <= 3; k++) {
			int ny = y + dy[dir] * k;
			int nx = x + dx[dir] * k;
			int ndir = dir;

			if (!check(ny, nx)) break;

			if (visited[ny][nx][ndir] > visited[y][x][dir] + 1) {
				visited[ny][nx][ndir] = visited[y][x][dir] + 1;
				q.push({ ny, nx, ndir });
			}
		}

		// 2. 방향 틀기
		int ny = y;
		int nx = x;

		if (dir == 1 || dir == 2) {
			// 동, 서
			int ndir = 3;
			if (check(ny, nx) && visited[ny][nx][ndir] > visited[y][x][dir] + 1) {
				visited[ny][nx][ndir] = visited[y][x][dir] + 1;
				q.push({ ny, nx, ndir });;
			}

			ndir = 4;
			if (check(ny, nx) && visited[ny][nx][ndir] > visited[y][x][dir] + 1) {
				visited[ny][nx][ndir] = visited[y][x][dir] + 1;
				q.push({ ny, nx, ndir });
			}
		}
		else if (dir == 3 || dir == 4) {
			// 남, 북
			int ndir = 1;
			if (check(ny, nx) && visited[ny][nx][ndir] > visited[y][x][dir] + 1) {
				visited[ny][nx][ndir] = visited[y][x][dir] + 1;
				q.push({ ny, nx, ndir });
			}

			ndir = 2;
			if (check(ny, nx) && visited[ny][nx][ndir] > visited[y][x][dir] + 1) {
				visited[ny][nx][ndir] = visited[y][x][dir] + 1;
				q.push({ ny, nx, ndir });
			}
		}
	}


	return 0;
}