#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct TREE {
	int y, x, dir;
}TREE;

int n;
char arr[55][55];
int visited[55][55][2];
const int dy[5] = { -1,0,1,0 }; // 상, 우, 하, 좌
const int dx[5] = { 0,1,0,-1 };
vector<pii> s, e;
int sy, sx, sdir = -1, ey, ex, edir = -1; // 중심 좌표, 방향
// 0 : 세로, 1 : 가로
int mn = 987654321;

bool check(int y, int x, int dir) {
	if (y < 0 || x < 0 || y >= n || x >= n) return false;
	if (arr[y][x] == '1') return false;
	return true;
}

bool check_rotate(int y, int x) {
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n || arr[i][j] == '1') return false;
		}
	}

	return true;
}

void bfs() {
	visited[sy][sx][sdir] = 1;
	queue<TREE> q;
	q.push({ sy, sx, sdir });

	while (!q.empty()) {
		TREE now = q.front();
		q.pop();

		if (now.y == ey && now.x == ex && now.dir == edir) {
			cout << visited[ey][ex][edir] - 1 << "\n";
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (now.dir == 0) { // 세로
				int ny1 = ny - 1;
				int ny2 = ny + 1;

				if (check(ny, nx, now.dir) && check(ny1, nx, now.dir) && check(ny2, nx, now.dir) && !visited[ny][nx][now.dir]) {
					q.push({ ny, nx, now.dir });
					visited[ny][nx][now.dir] = visited[now.y][now.x][now.dir] + 1;
				}

			}
			else if (now.dir == 1) { // 가로
				int nx1 = nx - 1;
				int nx2 = nx + 1;

				if (check(ny, nx, now.dir) && check(ny, nx1, now.dir) && check(ny, nx2, now.dir) && !visited[ny][nx][now.dir]) {
					q.push({ ny, nx, now.dir });
					visited[ny][nx][now.dir] = visited[now.y][now.x][now.dir] + 1;
				}
			}

			// 회전
			if(check_rotate(now.y, now.x) && !visited[now.y][now.x][!now.dir]) {
				visited[now.y][now.x][!now.dir] = visited[now.y][now.x][now.dir] + 1;
				q.push({ now.y, now.x, !now.dir });
			}
		}
	}
}

void print_arr() {
	cout << "=========================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j][0] << " ";
		}
		cout << "\n";
	}
	cout << "=========================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j][1] << " ";
		}
		cout << "\n";
	}
	cout << "=========================\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				s.push_back({ i ,j });
				arr[i][j] = '0';
			}
			else if (arr[i][j] == 'E') {
				e.push_back({ i, j });
				arr[i][j] = '0';
			}
		}
	}

	for (int i = 0; i < s.size(); i++) {
		sy += s[i].first;
		sx += s[i].second;
		if (sdir != -1) continue;
		if (s[i].first < s[i + 1].first) sdir = 0;
		else if (s[i].second < s[i + 1].second) sdir = 1;
	}

	for (int i = 0; i < e.size(); i++) {
		ey += e[i].first;
		ex += e[i].second;
		if (edir != -1) continue;
		if (e[i].first < e[i + 1].first) edir = 0;
		else if (e[i].second < e[i + 1].second) edir = 1;
	}
	sy /= 3; sx /= 3; ey /= 3; ex /= 3;

	//cout << sy << " : " << sx << "\n" << ey << " : " << ex << "\n";
	//cout << sdir << " : " << edir << "\n";

	bfs();
	// print_arr();
	cout << 0 << "\n";

	
	return 0;
}