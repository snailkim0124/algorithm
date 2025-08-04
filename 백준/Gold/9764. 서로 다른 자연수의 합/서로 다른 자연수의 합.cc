#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
const int mod = 100999;
int dp[2005][2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i <= 2000; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= 2000; j++) {
			if (i < j) {
				dp[i][j] = dp[i][j - 1];
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1];
			}
			dp[i][j] %= mod;
		}
	}
	
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n][n] << "\n";
	}

	return 0;
}