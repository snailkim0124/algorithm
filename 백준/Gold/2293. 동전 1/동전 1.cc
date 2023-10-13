#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int dp[10005];
const int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		int money;
		cin >> money;
		for (int j = money; j <= k; j++) {
			dp[j] += dp[j - money];
		}
	}

	cout << dp[k];

	return 0;
}