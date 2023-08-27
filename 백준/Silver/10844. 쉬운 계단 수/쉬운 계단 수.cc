#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

typedef long long ll;
ll n, sum;
ll dp[1005][1005];
ll mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % mod;
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
		dp[i][9] = dp[i - 1][8] % mod;
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= mod;
	}

	cout << sum;

	return 0;
}