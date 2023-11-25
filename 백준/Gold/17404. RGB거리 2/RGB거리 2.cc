#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[10001][3];
int arr[10001][3];
const int INF = 987654321;
int res = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	// r
	dp[1][0] = arr[1][0];
	dp[1][1] = INF;
	dp[1][2] = INF;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	res = min(res, min(dp[n][1], dp[n][2]));

	// g
	dp[1][1] = arr[1][1];
	dp[1][0] = INF;
	dp[1][2] = INF;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	res = min(res, min(dp[n][0], dp[n][2]));

	// b
	dp[1][2] = arr[1][2];
	dp[1][0] = INF;
	dp[1][1] = INF;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	res = min(res, min(dp[n][0], dp[n][1]));

	cout << res;

	return 0;
}