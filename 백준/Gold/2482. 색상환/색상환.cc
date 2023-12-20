#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int dp[1005][1005];
const int mod = 1000000003;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
		}
	}

	cout << (dp[n-1][k] + dp[n-3][k-1]) % mod;
	
	return 0;
}