#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int n, m;
int arr[105][105];
int visited[105][105];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> v;
int res, Time;

int bfs() { 
	int cnt = 0;
	visited[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	Time++;

	while (!q.empty()) { // bfs 방법
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] == 0) { // 치즈가 없을 때
				q.push({ ny, nx });
			}
			else { // 치즈가 있을 때
				arr[ny][nx] = 0; //치즈 녹이기
				cnt++;
			}
			visited[ny][nx] = 1;
		}
	}

	if (cnt == 0) { // 치즈 개수 없으면 결과값 출력
		Time--;
		cout << Time << "\n" << res;
		return 1;
	}
	else {
		res = cnt; // 치즈 개수
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; // 입력
		}
	}

	while (1) {
		if (bfs()) break; // 치즈가 다 없을 때
		fill(&visited[0][0], &visited[0][0] + 105 * 105, 0); //초기화
	}

	return 0;
}