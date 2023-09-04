#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int r, c, res;
char arr[1504][1504];
int visited[1504][1504], visited_swan[1504][1504];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
pair<int, int> swan_start;
queue<pair<int, int>> water, water2, swan, ice;
string s;

int bfs() { // 백조가 방문할수 있는 위치 탐색
	while (!swan.empty()) {
		int y = swan.front().first;
		int x = swan.front().second;
		swan.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
			if (visited_swan[ny][nx]) continue;
			visited_swan[ny][nx] = 1;
			if (arr[ny][nx] == '.') swan.push({ ny, nx });
			if (arr[ny][nx] == 'X') ice.push({ ny, nx });
			if (arr[ny][nx] == 'L') return 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'L') { // 백조 시작 위치 받기
				swan_start.first = i;
				swan_start.second = j;
			}
			if (arr[i][j] == '.' || arr[i][j] == 'L') { // 물 좌표 받기
				visited[i][j] = 1;
				water.push({ i,j });
			}
		}
	}
	
	swan.push({ swan_start.first, swan_start.second });
	visited_swan[swan_start.first][swan_start.second] = 1;

	while (1) {
		if (bfs() != 0) break;

		while (!water.empty()) { // 얼음을 물로 바꾸는 작업
			int y = water.front().first;
			int x = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] == 'X') {
					visited[ny][nx] = 1;

					water2.push({ ny, nx });
					arr[ny][nx] = '.';
				}
			}
		}

		water = water2;
		swan = ice;
		water2 = queue<pair<int, int>> ();
		ice = queue<pair<int, int>> ();
		res++;
	}

	cout << res;
	return 0;
}