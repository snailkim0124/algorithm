#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <memory.h>

using namespace std;

int t, I;
int visited[305][305];
int arr[305][305];
int startx, starty;
int endx, endy;
int dy[8] = { -1, -2, -2, -1,1,2,2,1 }; // 체스판 이동
int dx[8] = { -2, -1, 1, 2,-2,-1,1,2 };
queue<pair<int, int>> q;

void bfs(int X, int Y) { // bfs 방법
	q.push({ X,Y });
	visited[X][Y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == endx && y == endy) { // end위치가 되면 이때까지 누적한 arr 출력
			cout << arr[x][y] << "\n";
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
			if (visited[nx][ny]) continue;
			q.push({ nx, ny });
			visited[nx][ny] = 1;
			arr[nx][ny] = arr[x][y] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		q = queue<pair<int, int>>(); // 초기화
		fill(&arr[0][0], &arr[0][0] + 305 * 305, 0);
		fill(&visited[0][0], &visited[0][0] + 305 * 305,0);

		cin >> I; //체스판 한 변의 길이
		cin >> startx >> starty;
		cin >> endx >> endy;

		bfs(startx, starty);

	}
	return 0;
}