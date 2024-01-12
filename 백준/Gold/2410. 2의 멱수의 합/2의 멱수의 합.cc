#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[1000005];
const int INF = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		if (i % 2 == 1) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] + dp[i / 2];
		}
		dp[i] %= INF;
	}

	cout << dp[n];
	

	return 0;
}