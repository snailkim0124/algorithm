#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll arr[205][205], dp[205][205];
ll ans = LLONG_MIN;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) { // x1
		for (int k = i; k <= n; k++) { // x2
			for (int j = 1; j <= m; j++) { // y1
				for (int l = j; l <= m; l++) { // y2
					ans = max(ans, dp[k][l] - dp[i - 1][l] - dp[k][j - 1] + dp[i - 1][j - 1]);
				}
			}
		}
	}

	cout << ans;
	return 0;
}