#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, s;
vector<ll> x;

bool check(ll mid) {
	ll cnt = 1;
	ll lst = x[0];

	for (int i = 1; i < n; i++) {
		if (x[i] - lst >= mid) {
			cnt++;
			lst = x[i];

			if (cnt == s) return true;
		}
	}

	return false;
}

void solve() {
	cin >> n >> s;
	x.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	sort(all(x));

	ll left = 0;
	ll right = x[n - 1];
	ll res = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << res << "\n";
	x.clear();
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