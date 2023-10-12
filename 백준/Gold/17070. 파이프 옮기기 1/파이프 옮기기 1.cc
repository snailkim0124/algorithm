#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[20][20];
int dp[20][20][3];

int check(int y, int x, int d) { // 갈수 있는지 체크
	if (d == 0 || d == 2) {
		if (!arr[y][x]) return 1;
	}
	else if (d == 1) {
		if (arr[y][x] == 0 && arr[y - 1][x] == 0 && arr[y][x - 1] == 0) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

			if (check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
			if (check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}

	int res = dp[n][n][0];
	res += dp[n][n][1];
	res += dp[n][n][2];

	cout << res;

	return 0;
}