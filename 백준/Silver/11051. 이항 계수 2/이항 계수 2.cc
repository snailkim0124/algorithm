#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

typedef long long int ll;
int n, k;
int dp[1005][1005];
int mod = 10007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[i][i] = i;
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}

	cout << dp[n][k];
	return 0;
}