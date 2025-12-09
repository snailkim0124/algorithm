#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
ll dp[55][55];
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;

	// 안되는 케이스
	dp[0][0] = 1;
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j <= i; j++) {
			// (
			if (j + 1 <= 50) {
				dp[i][j] += dp[i - 1][j + 1];
			}

			// )
			if (j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1];
			}
		}
	}

	// cout << dp[n][0] << "\n";

	if ((1LL << n) - dp[n][0] <= k) {
		cout << -1 << "\n";
		exit(0);
	}

	ll now = 0;
	bool flag = false;

	for (int i = 0; i < n; i++) {
		ll cnt = 0;

		ll nxt = now + 1;
		bool nflag = flag;

		if (nflag) {
			cnt = (1LL << (n - 1 - i));
		}
		else {
			ll tmp = 0;
			if (nxt <= (n - 1 - i)) tmp = dp[n - 1 - i][nxt];
			cnt = (1LL << (n - 1 - i)) - tmp;
		}

		// k보다 이전이면 ( 아니면 )
		if (k < cnt) {
			ans += "(";
			now = nxt;
			flag = nflag;
		}
		else {
			ans += ")";
			k -= cnt;

			now--;
			if (now < 0) flag = true;
		}
	}

	cout << ans << "\n";

	return 0;
}