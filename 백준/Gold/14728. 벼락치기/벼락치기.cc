#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[100005];
int n, t, k, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t;
	while (n--) {
		cin >> k >> s;
		for (int i = t; i >= k; i--) {
			dp[i] = max(dp[i], dp[i - k] + s);
		}
	}

	cout << dp[t];

	return 0;
}