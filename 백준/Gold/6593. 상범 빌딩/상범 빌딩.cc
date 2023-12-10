#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct pos {
	int z,y,x;
}pos;

int l, r, c;
char arr[35][35][35];
int visited[35][35][35];
const int dz[] = { 0,0,0,0,1,-1 };
const int dy[] = { -1,0,1,0, 0,0 };
const int dx[] = { 0,1,0,-1, 0,0 };
int startx, starty, startz, endx, endy, endz;
const int INF = 987654321;
queue<pos> q;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		memset(arr, 0, sizeof(arr));
		fill(&visited[0][0][0], &visited[0][0][0] + 35 * 35 * 35, INF);
		q = queue<pos>();

		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {
						startz = i;
						starty = j;
						startx = k;
					}
					else if (arr[i][j][k] == 'E') {
						endz = i;
						endy = j;
						endx = k;
					}
				}
			}
		}

		q.push({ startz, starty, startx });
		visited[startz][starty][startx] = 0;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l) continue;
				if (arr[nz][ny][nx] == '#') continue;
				if (visited[nz][ny][nx] > visited[z][y][x] + 1) {
					visited[nz][ny][nx] = visited[z][y][x] + 1;
					q.push({ nz, ny, nx });
				}
			}
		}

		if (visited[endz][endy][endx] == INF) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << visited[endz][endy][endx] << " minute(s).\n";
		}
	}


	return 0;
}