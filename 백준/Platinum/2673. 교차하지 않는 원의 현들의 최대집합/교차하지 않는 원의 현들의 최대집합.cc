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
int pos[105];
int dp[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pos[a] = b;
		pos[b] = a;
	}

	for (int sz = 1; sz <= 100; sz++) {
		for (int l = 1; l + sz - 1 <= 100; l++) {
			int r = l + sz - 1;

			dp[l][r] = dp[l][r - 1];

			int k = pos[r];
			if (l <= k && k < r) {
				dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r - 1] + 1);
			}
		}
	}

	cout << dp[1][100] << "\n";
	
	return 0;
}