#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define y1 aaa

int n, m;
char arr[305][305];
int visited[305][305];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int x1, y1, x2, y2;
int cnt;

int bfs(int starty, int startx) {
	queue<pair<int, int>> q;
	q.push({ starty, startx });
	visited[starty][startx] = 1;

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == y2 && nx == x2) {
				return 1;
			}
			if (nx < 1 || ny < 1 || nx >= m + 1 || ny >= n + 1) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				if (arr[ny][nx] == '1') {
					arr[ny][nx] = '0';
				}
				else if (arr[ny][nx] == '0') {
					q.push({ ny, nx });
				}
			}
		}
	}

	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		fill(&visited[0][0], &visited[0][0] + 305 * 305, 0);
		cnt++;
		if (bfs(y1, x1) == 1) {
			break;
		}
	}

	cout << cnt;

	return 0;
}