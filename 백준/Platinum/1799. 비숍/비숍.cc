#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[15][15];
int visited[15][15];
const int dy[4] = { -1,-1,1,1 };
const int dx[4] = { -1,1,1,-1 };
int res[2];

// 흑, 백으로 나눠서 탐색
void dfs(int idx, int cnt, int color) {
	if (idx >= n * n) {
		res[color] = max(res[color], cnt);
		return;
	}

	int y = idx / n;
	int x = idx % n;

	if ((y + x) % 2 == color && arr[y][x] == 1 && !visited[y][x]) {
		bool flag = true;
		for (int i = 0; i < 4; i++) {
			int ny = y, nx = x;
			while (1) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
				if (visited[ny][nx]) {
					flag = false;
					break;
				}
			}

			if (!flag) break; // 한번 방문한경우
		}

		if (flag) { // 새로놓은 비숍이 겹치지 않는경우
			visited[y][x] = 1;
			dfs(idx + 1, cnt + 1, color);
			visited[y][x] = 0;
		}
	}

	dfs(idx + 1, cnt, color);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0);
	dfs(0, 0, 1);

	cout << res[0] + res[1] << "\n";

	return 0;
}