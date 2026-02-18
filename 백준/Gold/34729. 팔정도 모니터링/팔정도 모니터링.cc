#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, r;
vector<pll> v;

ll go(ll p) {
	ll sum = 0;
	// F(t,0)
	for (auto [x, y] : v) {
		sum += abs(p - x) + abs(y);
	}

	// F(0,t)
	for (auto [x, y] : v) {
		sum += abs(x) + abs(p - y);
	}

	// F(t,t)
	for (auto [x, y] : v) {
		sum += abs(p - x) + abs(p - y);
	}

	// F(t,-t)
	for (auto [x, y] : v) {
		sum += abs(p - x) + abs(-p - y);
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(all(v));

	ll left = -r;
	ll right = r;
	while (right - left >= 3) {
		ll p1 = (left * 2 + right) / 3;
		ll p2 = (left + right * 2) / 3;

		if (go(p1) <= go(p2)) {
			right = p2;
		}
		else left = p1;
	}

	ll ans = LLONG_MAX;
	for (ll i = left; i <= right; i++) {
		ans = min(ans, go(i));
	}

	cout << ans << "\n";

	return 0;
}