#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int n;
int dp[100004];
int mod = 9901;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n+1; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % mod;
	}

	cout << dp[n+1] % 9901;
	return 0;
}