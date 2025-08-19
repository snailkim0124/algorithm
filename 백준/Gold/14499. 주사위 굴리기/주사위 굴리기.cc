#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, y, x, k;
int arr[25][25];
const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { 1, -1, 0, 0 };
int dice[7];
// 위, 북, 동, 서, 남, 아래
// 1, 2, 3, 4, 5, 6

void rotate_dice(int dir) {
	int d1 = dice[1], d2 = dice[2], d3 = dice[3];
	int d4 = dice[4], d5 = dice[5], d6 = dice[6];
	if (dir == 0) {
		dice[1] = d4, dice[3] = d1;
		dice[4] = d6, dice[6] = d3;
	}
	else if (dir == 1) {
		dice[1] = d3, dice[3] = d6;
		dice[4] = d1, dice[6] = d4;
	}
	else if (dir == 2) {
		dice[1] = d5, dice[2] = d1;
		dice[5] = d6, dice[6] = d2;
	}
	else if (dir == 3) {
		dice[1] = d2, dice[2] = d6;
		dice[5] = d1, dice[6] = d5;
	}
}

void move_dice(int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	// 갈 수 있는지 체크
	if (ny < 0 || nx < 0 || ny >= n || nx >= m) return;
	
	rotate_dice(dir);

	if (arr[ny][nx] == 0) {
		arr[ny][nx] = dice[6];
	}
	else {
		dice[6] = arr[ny][nx];
		arr[ny][nx] = 0;
	}

	cout << dice[1] << "\n";

	y = ny; x = nx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (k--) {
		int cmd;
		cin >> cmd;
		move_dice(cmd - 1);
	}
	
	return 0;
}