#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
int a[10005];
int dp[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] += dp[j - a[i]];
		}
	}

	cout << dp[k];
	
	return 0;
}