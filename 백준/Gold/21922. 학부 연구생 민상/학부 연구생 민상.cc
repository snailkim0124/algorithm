#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[2005][2005];
int checked[2005][2005]; // 개수
int visited[2005][2005][4]; // 루프 확인용
int starty, startx;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<pii> air;
int cnt;

void go(int dir, int starty, int startx) {
	int y = starty;
	int x = startx;
	visited[y][x][dir] = 1;
	checked[y][x] = 1;

	while (1) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
		if (arr[ny][nx] == 9 || visited[ny][nx][dir]) break;

		checked[ny][nx] = 1;
		visited[ny][nx][dir] = 1;
		if (arr[ny][nx] == 1) {
			if (dir == 1 || dir == 3) break;
		}
		else if (arr[ny][nx] == 2) {
			if (dir == 0 || dir == 2) break;
		}
		else if (arr[ny][nx] == 3) {
			if (dir == 0) dir = 1;
			else if (dir == 1) dir = 0;
			else if (dir == 2) dir = 3;
			else if (dir == 3) dir = 2;

		}
		else if (arr[ny][nx] == 4) {
			if (dir == 0) dir = 3;
			else if (dir == 1) dir = 2;
			else if (dir == 2) dir = 1;
			else if (dir == 3) dir = 0;
		}

		y = ny; x = nx;
	}
}

void count_air() {
	//cout << "=============================\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << checked[i][j] << " ";
	//		if (checked[i][j]) cnt++;
	//	}
	//	cout << "\n";
	//}
	//cout << "cnt : " << cnt << "\n";
	//cout << "=============================\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (checked[i][j]) cnt++;
		}
	}
	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) air.push_back({ i, j });
		}
	}

	for (auto it : air) {
		// cout << it.first << " : " << it.second << "\n";
		for (int i = 0; i < 4; i++) {
			// 상 우 하 좌
			go(i, it.first, it.second);
		}
	}

	count_air();

	return 0;
}