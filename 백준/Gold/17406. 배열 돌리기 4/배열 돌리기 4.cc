#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct ROTATE {
	int r, c, s;
} ROTATE;

int n, m, k;
int arr[55][55];
vector<ROTATE> v;
int visited[10];
int res = 987654321;

void rotate_arr(int r, int c, int s) {
	// 회전
	for (int k = 1; k <= s; k++) {
		// 좌
		for (int i = r - k; i < r + k; i++) {
			swap(arr[i][c - k], arr[i + 1][c - k]);
		}
		// 하
		for (int j = c - k; j < c + k; j++) {
			swap(arr[r + k][j], arr[r + k][j + 1]);
		}
		// 우
		for (int i = r + k; i > r - k; i--) {
			swap(arr[i][c + k], arr[i - 1][c + k]);
		}
		// 상
		for (int j = c + k; j > c - k; j--) {
			swap(arr[r - k][j], arr[r - k][j - 1]);
		}
		swap(arr[r - k][c - k], arr[r - k][c - k + 1]);
	}
	return;
}

void dfs(int depth) {
	if (depth == v.size()) {
		int mn = 987654321;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += arr[i][j];
			}
			mn = min(mn, sum);
		}

		res = min(res, mn);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			int tmp[55][55] = { 0 };
			memcpy(tmp, arr, sizeof(arr));
			rotate_arr(v[i].r, v[i].c, v[i].s);
			visited[i] = 1;

			dfs(depth + 1);

			memcpy(arr, tmp, sizeof(tmp));
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	while (k--) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r, c, s });
	}

	dfs(0);

	cout << res;

	return 0;
}