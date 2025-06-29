#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll arr[105][105];
ll dp[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n) break;
			if (i + arr[i][j] <= n) dp[i + arr[i][j]][j] += dp[i][j];
			if (j + arr[i][j] <= n) dp[i][j + arr[i][j]] += dp[i][j];
		}
	}
	cout << dp[n][n] << "\n";

	return 0;
}