#include <bits/stdc++.h>

using namespace std;

int t;
int h, w;
int startx, starty;
char a[1005][1005];
int fire[1005][1005];
int person[1005][1005];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;  // 초기화
		int res = 0;
		fill(&fire[0][0], &fire[0][0] + 1005 * 1005, 987654321);
		fill(&person[0][0], &person[0][0] + 1005 * 1005, 0);
		fill(&a[0][0], &a[0][0] + 1005 * 1005, 0);

		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];

				if (a[i][j] == '*') { // 불 위치
					fire[i][j] = 1;
					q.push({ i, j });
				}
				else if (a[i][j] == '@') { // 상근 위치
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
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
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

			if (x == w - 1 || y == h - 1 || x == 0 || y == 0) { // 가장자리(탈출)
				res = person[y][x];
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (person[ny][nx] || a[ny][nx] == '#') continue;
				if (fire[ny][nx] <= person[y][x] + 1) continue; // 불 보다 빨라야 함
				person[ny][nx] = person[y][x] + 1;
				q.push({ ny, nx });

			}
		}

		if (res != 0) cout << res << "\n";
		else cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}