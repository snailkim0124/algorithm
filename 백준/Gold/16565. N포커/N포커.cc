#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
const int mod = 10007;
int dp[55][55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (n <= 3) {
		cout << 0 << "\n";
		exit(0);
	}

	for (int i = 0; i <= 50; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= 50; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}

	int res = 0;
	for (int i = 1; i <= n / 4; i++) {
		if (i % 2 == 1) {
			res += (dp[13][i] * dp[52 - i * 4][n - i * 4]) % mod;
			res %= mod;
		}
		else {
			res -= (dp[13][i] * dp[52 - i * 4][n - i * 4]) % mod;
			res = (res + mod) % mod;
		}
	}

	cout << res << "\n";

	return 0;
}