#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[1000005];
const int INF = 987654321;

void trace(int n) {
	if (n == 0) return;
	cout << n << " ";
	if (n % 3 == 0 && dp[n] == (dp[n / 3] + 1)) trace(n / 3);
	else if (n % 2 == 0 && dp[n] == (dp[n / 2] + 1)) trace(n / 2);
	else if ((n - 1 >= 0) && (dp[n] == (dp[n - 1] + 1))) trace(n - 1);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	fill(dp, dp + 1000005, INF);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	}
	cout << dp[n] << "\n";
	trace(n);

	return 0;
}