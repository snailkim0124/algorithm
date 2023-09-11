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
int res, cnt;

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (arr[y][x] == 1) { // 치즈 확인
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}

	return;
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
		cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 105 * 105, 0);
		bool check = false;
		v.clear(); // 초기화

		dfs(0, 0);
		for (int i = 0; i < v.size(); i++) {
			cnt++;
			arr[v[i].first][v[i].second] = 0; // 치즈 녹이기
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) check = true;
			}
		}
		res++;
		if (check == false) break; // 치즈 남은 여부

	}

	cout << res << "\n" << cnt;
	return 0;
}