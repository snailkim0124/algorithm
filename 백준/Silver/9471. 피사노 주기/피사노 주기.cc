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
ll dp[1500005];

void solve() {
	ll n, m;
	cin >> n >> m;
	
	ll prev = 1;
	ll now = 1;

	for (int i = 1; i <= m * m; i++) {
		ll tmp = (prev + now) % m;
		prev = now;
		now = tmp;

		if (prev == 1 && now == 1) {
			cout << n << " " << i << "\n";
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}