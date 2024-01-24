#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, m;
int arr[10005];
int dp[10005];
const int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(dp, dp + 10005, 0);
		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cin >> m;

		for (int i = 0; i < n; i++) {
			for (int j = arr[i]; j <= m; j++) {
				dp[j] += dp[j - arr[i]];
			}
		}

		cout << dp[m] << "\n";
	}

	return 0;
}