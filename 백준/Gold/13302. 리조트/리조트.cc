#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int no[105];
int dp[105][105]; // 며칠, 쿠폰
int res = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		no[num]++;
	}

	fill(&dp[0][0], &dp[0][0] + 105 * 105, INT_MAX);

	dp[0][0] = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 50; j++) {
			if (dp[i][j] == INT_MAX) continue;

			// 쉬는 날
			if (i + 1 <= n && no[i + 1]) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
				continue;
			}
			// 쿠폰 사용
			if (i + 1 <= n && j >= 3) dp[i + 1][j - 3] = min(dp[i + 1][j - 3], dp[i][j]);


			// 1일
			if (i + 1 <= n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 10000);
			// 3일
			for (int k = 1; k <= 3; k++) {
				if (i + k <= n) dp[i + k][j + 1] = min(dp[i + k][j + 1], dp[i][j] + 25000);
			}
			// 5일
			for (int k = 1; k <= 5; k++) {
				if (i + k <= n) dp[i + k][j + 2] = min(dp[i + k][j + 2], dp[i][j] + 37000);
			}
		}
	}
	
	for (int i = 0; i <= 100; i++) {
		res = min(res, dp[n][i]);
	}

	cout << res << "\n";

	return 0;
}