#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[50005];
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int mn = INF;
		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			mn = min(mn, dp[tmp]);
		}
		dp[i] = mn + 1;
	}

	cout << dp[n];

	return 0;
}