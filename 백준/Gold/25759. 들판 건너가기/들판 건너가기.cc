#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll arr[100005];
ll dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		ll now = arr[i];

		for (int j = 1; j <= 100; j++) {
			if (dp[j] != -1) {
				dp[now] = max(dp[now], dp[j] + (now - j) * (now - j));
			}
		}
		dp[now] = max(dp[now], 0LL);
	}

	ll res = 0;
	for (int j = 1; j <= 100; j++) {
		res = max(res, dp[j]);
	}

	cout << res << "\n";

	return 0;
}