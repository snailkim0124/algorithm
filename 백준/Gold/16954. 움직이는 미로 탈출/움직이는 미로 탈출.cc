#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char arr[10][10];
int starty, startx, endy, endx;
const int dy[9] = { 0,-1,-1,-1,0,0,1,1,1 };
const int dx[9] = { 0,-1,0,1,-1,1,-1,0,1 };


void wall_move() {
	for (int i = 7; i >= 1; i--) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}

	for (int j = 0; j < 8; j++) {
		arr[0][j] = '.';
	}
}

bool check_wall(int y, int x) {
	if (y - 1 >= 0 && arr[y - 1][x] == '#') return false;
	if (arr[y][x] == '#') return false;
	return true;
}

void bfs() {
	queue<pii> q;
	q.push({ starty, startx });

	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			int y, x;
			tie(y, x) = q.front();
			q.pop();

			for (int i = 0; i < 9; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
				if (!check_wall(ny, nx)) continue;
				if (ny == endy && nx == endx) {
					cout << 1;
					return;
				}
				if (arr[ny][nx] == '.') {
					q.push({ ny, nx });
				}
			}
		}
		wall_move();
	}

	cout << 0;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}

	starty = 7;
	startx = 0;
	endy = 0;
	endx = 7;

	bfs();

	return 0;
}