#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, k;
ll dp[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i <= 200; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= 200; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

			// 오버플로 방지
			if (dp[i][j] > 1e9) dp[i][j] = 9876543210;
		}
	}

	cin >> n >> m >> k;
	ll total = dp[n + m][n];

	if (total < k) {
		cout << -1 << "\n";
		exit(0);
	}

	string ans = "";
	ll sz = n + m;

	for (int i = 0; i < sz; i++) {
		// 나머지 처리
		if (n == 0) {
			ans += 'z';
			m--;
			continue;
		}

		if (m == 0) {
			ans += 'a';
			n--;
			continue;
		}

		// 분기
		ll tmp = dp[n - 1 + m][m];
		if (tmp >= k) {
			ans += 'a';
			n--;
		}
		else {
			ans += 'z';
			k -= tmp;
			m--;
		}
	}

	cout << ans << "\n";

	
	return 0;
}