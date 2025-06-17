#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll a, b;
ll dp[65];
ll mx;

ll countOne(ll x) {
	ll res = x & 1;

	for (int i = mx; i > 0; i--) {
		// 비트 켜져있는지 확인
		if (x & (1LL << i)) {
			x -= 1LL << i;
			res += dp[i - 1] + x + 1;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	
	mx = log2(10e16);

	dp[0] = 1;
	for (int i = 1; i < mx; i++) {
		dp[i] = 2 * dp[i - 1] + (1LL << i);
	}

	
	cout << countOne(b) - countOne(a - 1);

	return 0;
}
