#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll arr[35][35];
ll dp[35][35][3];

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
			if (arr[i][j + 1] == 0) dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
			if (arr[i + 1][j] == 0) dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
			if (arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0) dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];

		}
	}

	ll res = dp[n][n][0];
	res += dp[n][n][1];
	res += dp[n][n][2];

	cout << res;

	return 0;
}