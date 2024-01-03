#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[1000005];
const int mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	if (n == 0) {
		cout << 0 << "\n" << 0;
		exit(0);
	}

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= abs(n); i++) {
		dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
	}

	if (n < 0) {
		if (abs(n) % 2 == 0) {
			cout << -1 << "\n" << dp[abs(n)];
			exit(0);
		}
		else {
			cout << 1 << "\n" << dp[abs(n)];
		}
	}
	else cout << 1 << "\n" << dp[abs(n)];

	return 0;
}