#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 최소공배수만큼 사이클이 생김

	cin >> t;
	while (t--) {
		ll m, n, x, y;
		cin >> m >> n >> x >> y;

		ll ans = -1;

		if (y == n) y = 0;

		for (ll i = x; i <= m * n; i += m) {
			if (i % n == y) {
				ans = i;
				break;
			}
		}

		cout << ans << "\n";

	}

	
	return 0;
}