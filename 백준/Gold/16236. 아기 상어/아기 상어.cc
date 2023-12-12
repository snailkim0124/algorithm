#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct shark {
	int y, x, cnt; // 시간
}shark;

int n;
int arr[25][25];
int visited[25][25];
const int dy[4] = { -1,0,0,1 };
const int dx[4] = { 0,-1,1,0 };
int startx, starty; // 시작 위치
int lastx, lasty; // 최종 위치(갱신)
int fish, res;
int sharksize = 2;

int bfs(int Y, int X) {
	bool flag = false;
	memset(visited, 0, sizeof(visited));
	queue<shark> q;
	visited[Y][X] = 1;
	q.push({ Y, X, 0 }); // 초기값 설정
	int tmp = 0;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		if (arr[y][x] > 0 && arr[y][x] < sharksize && tmp == cnt) { // 가장 위쪽 그 다음 왼쪽
			if ((lasty > y) || (lasty == y && lastx > x)) {
				lastx = x;
				lasty = y;
				continue;
			}
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx] || arr[ny][nx] > sharksize) continue;

			if (arr[ny][nx] > 0 && arr[ny][nx] < sharksize && !flag) { // 물고기 먹을 수 있는 경우
				flag = true;
				lastx = nx;
				lasty = ny;
				tmp = cnt + 1;
				res += tmp;
			}
			else { // 물고기를 먹을 수 없는 경우
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx, cnt + 1 });
			}
		}
	}

	return flag;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				starty = i;
				startx = j;
				arr[i][j] = 0;
			}
		}
	}

	lastx = startx;
	lasty = starty;
	
	while (1) {
		if (bfs(lasty, lastx)) {
			fish++;
			arr[lasty][lastx] = 0;
			if (fish == sharksize) { // 먹은 개수가 크기랑 같은 경우
				sharksize++;
				fish = 0;
			}
		}
		else { // 못먹는 경우
			break;
		}
	}

	cout << res;


	return 0;
}