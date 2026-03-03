#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = 1e18;
ll m, n, l, g;
ll row[105][105], col[105][105];
ll dp[105][105][2][205]; // y, x, (col, row), 전환 횟수

void solve() {
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	cin >> m >> n >> l >> g;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n - 1; j++) {
			cin >> row[i][j];
		}
	}

	for (int i = 1; i <= m - 1; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> col[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	dp[1][1][0][0] = g;
	dp[1][1][1][0] = g;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= 200; k++) {
				if (dp[i][j][0][k] == -1 && dp[i][j][1][k] == -1) continue;

				ll nxt1 = dp[i][j][0][k] - col[i][j];
				if (i + 1 <= m && nxt1 >= 0) {
					dp[i + 1][j][0][k] = max(dp[i + 1][j][0][k], nxt1);
				}

				ll nxt2 = dp[i][j][0][k] - row[i][j];
				if (j + 1 <= n && nxt2 >= 0) {
					dp[i][j + 1][1][k + 1] = max(dp[i][j + 1][1][k + 1], nxt2);
				}

				ll nxt3 = dp[i][j][1][k] - col[i][j];
				if (i + 1 <= m && nxt3 >= 0) {
					dp[i + 1][j][0][k + 1] = max(dp[i + 1][j][0][k + 1], nxt3);
				}

				ll nxt4 = dp[i][j][1][k] - row[i][j];
				if (j + 1 <= n && nxt4 >= 0) {
					dp[i][j + 1][1][k] = max(dp[i][j + 1][1][k], nxt4);
				}

			}
		}
	}
	
	for (int k = 0; k <= 200; k++) {
		if (dp[m][n][0][k] >= 0 || dp[m][n][1][k] >= 0) {
			cout << ((m - 1) + (n - 1)) * l + k << "\n";
			return;
		}
	}

	cout << -1 << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}