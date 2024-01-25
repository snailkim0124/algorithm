#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10][10];
int res = 987654321;
const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;

// 0 빈칸, 1~5 CCTV, 6 벽, 7 확인
void go(int y, int x, int i) {
	i %= 4;
	while (1) {
		x += dx[i];
		y += dy[i];

		if (x < 0 || y < 0 || x >= m || y >= n || arr[y][x] == 6) return;
		if (arr[y][x] == 0) {
			arr[y][x] = 7;
		}
	}
}

void dfs(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << arr[i][j] << " ";
				if (arr[i][j] == 0) cnt++;
			}
			//cout << "\n";
		}
		res = min(res, cnt);
		return;
	}

	int y = cctv[idx].first;
	int x = cctv[idx].second;
	int tmp[10][10] = { 0 };

	// 임시 배열 계속 초기화
	memcpy(tmp, arr, sizeof(arr));

	for (int i = 0; i < 4; i++) {
		memcpy(arr, tmp, sizeof(tmp));
		if (arr[y][x] == 1) {
			go(y, x, i); // 한 방향
		}
		else if (arr[y][x] == 2) {
			// 직선
			go(y, x, i);
			go(y, x, i + 2);
		}
		else if (arr[y][x] == 3) {
			// 직각
			go(y, x, i);
			go(y, x, i + 1);
		}
		else if (arr[y][x] == 4) {
			// 3방향
			go(y, x, i);
			go(y, x, i + 1);
			go(y, x, i + 2);
		}
		else if (arr[y][x] == 5) {
			// 4방향
			go(y, x, i);
			go(y, x, i + 1);
			go(y, x, i + 2);
			go(y, x, i + 3);
		}

		dfs(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;  i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (1 <= arr[i][j] && arr[i][j] <= 5) {
				cctv.push_back({ i, j });
			}
		}
	}

	dfs(0);

	cout << res;

	return 0;
}