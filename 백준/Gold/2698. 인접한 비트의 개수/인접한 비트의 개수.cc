#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
int dp[105][105][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[1][0][0] = dp[1][0][1] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}


	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}

	return 0;
}