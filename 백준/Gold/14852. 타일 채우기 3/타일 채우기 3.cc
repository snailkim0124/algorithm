#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
ll dp[1000005][2];
ll mod = 1000000007;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[0][0] = 0;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i][1] = (dp[i - 3][0] + dp[i - 1][1]) % mod;
		dp[i][0] = (dp[i][1] * 2 + dp[i - 1][0] * 2 + dp[i - 2][0] * 3) % mod;
	}

	cout << dp[n][0] % mod;
	return 0;
}