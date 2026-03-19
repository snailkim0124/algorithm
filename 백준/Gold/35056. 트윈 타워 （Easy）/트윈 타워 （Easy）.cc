#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = LLONG_MAX;
ll n;
ll a[2005];
ll b[2005];
ll dp[2005][2005][2];

ll go(int idx, int cost, int flag) {
	if (cost == 0) return 0;
	if (idx > n) return -INF;
	if (dp[idx][cost][flag] != -1) return dp[idx][cost][flag];

	ll res = 0;
	// 건설 안하는 경우
	res = max(res, go(idx + 1, cost, 0));

	// 건설 하는 경우
	res = max(res, go(idx + 1, cost - 1, 1) + a[idx]);

	// 전이 건설된 경우
	if (flag == 1) {
		res = max(res, go(idx + 1, cost - 1, 0) + a[idx] + b[idx - 1]);
	}

	return dp[idx][cost][flag] = res;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		cin >> b[i];
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		ll ans = go(1, i, 0);
		cout << ans << "\n";
	}



	return 0;
}