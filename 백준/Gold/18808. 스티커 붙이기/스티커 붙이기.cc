#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int r, c;
int sticker[15][15];
int arr[45][45];
int res;

void rotate_right() {
	int tmp[15][15] = { 0 };
	memcpy(tmp, sticker, sizeof(sticker));

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			sticker[i][j] = tmp[r - j - 1][i];
		}
	}

	swap(r, c);
}

bool check(int y, int x) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1 && arr[y + i][x + j] == 1) {
				return false;
			}
		}
	}
	// arr에 계속 저장
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1) {
				arr[y + i][x + j] = 1;
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			bool flag = false;
			for (int i = 0; i <= n - r; i++) {
				for (int j = 0; j <= m - c; j++) {
					if (check(i, j)) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
			rotate_right(); // 회전
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += arr[i][j];
		}
	}

	cout << res;

	return 0;
}