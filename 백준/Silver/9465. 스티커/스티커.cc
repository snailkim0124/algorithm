#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int t;
int n;
int a[2][100004];
int dp[2][100004];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		fill(a[0], a[0] + 2 * 100004, 0);
		fill(dp[0], dp[0] + 2 * 100004, 0);
		long long int res = 0;
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> a[j][k];
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];
		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j-2]) + a[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j-2]) + a[1][j];
		}
		res = max(dp[0][n], dp[1][n]);
		cout << res << "\n";
	}
	return 0;
}