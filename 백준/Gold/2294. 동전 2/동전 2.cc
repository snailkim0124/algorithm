#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int dp[10005];
const int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	fill(dp, dp + 10005, INF);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		int money;
		cin >> money;
		for (int j = money; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - money] + 1);
		}
	}

	if (dp[k] == INF) cout << -1;
	else cout << dp[k];

	return 0;
}