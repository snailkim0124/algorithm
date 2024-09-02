#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int dp[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[1] = 1;
	dp[3] = 1;
	dp[4] = 1;

	cin >> n;

	for (int i = 5; i <= n; i++) {
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) dp[i] = 1;
	}

	if (dp[n]) cout << "SK";
	else cout << "CY";

	return 0;
}