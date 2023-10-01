#include <bits/stdc++.h>

using namespace std;

int r, c;
char a[1005][1005];
int fire[1005][1005];
int person[1005][1005];
queue<pair<int, int>>q;
int startx, starty;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(&fire[0][0], &fire[0][0] + 1005 * 1005, 987654321); // 초기화
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];

			if (a[i][j] == 'F') { // 불 위치
				fire[i][j] = 1;
				q.push({ i, j });
			}
			else if (a[i][j] == 'J') { // 지훈 위치
				person[i][j] = 1;
				starty = i;
				startx = j;
			}
		}
	}

	while (!q.empty()) { // 불 최단거리 탐색
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (fire[ny][nx] != 987654321 || a[ny][nx] == '#') continue;
			fire[ny][nx] = fire[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	q.push({ starty, startx });
	while (!q.empty()) { // 사람 최단거리 탐색
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (x == c - 1 || y == r - 1 || x == 0 || y == 0) { // 가장자리(탈출)
			res = person[y][x];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (person[ny][nx] || a[ny][nx] == '#') continue;
			if (fire[ny][nx] <= person[y][x] + 1) continue; // 불 보다 빨라야 함
			person[ny][nx] = person[y][x] + 1;
			q.push({ ny, nx });

		}
	}

	if (res != 0) cout << res;
	else cout << "IMPOSSIBLE";
	
	return 0;
}