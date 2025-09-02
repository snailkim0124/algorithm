#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, q;
vector<pll> va;
vector<ll> v;
ll pax[200005], pa[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll a, x;
		cin >> a >> x;
		va.push_back({ x, a });
		v.push_back(x);
	}

	sort(all(va));
	sort(all(v));

	for (int i = 1; i <= n; i++) {
		pax[i] = pax[i - 1] + va[i - 1].first * va[i - 1].second;
		pa[i] = pa[i - 1] + va[i - 1].second;
	}

	while (q--) {
		ll qq;
		cin >> qq;
		ll k = lower_bound(all(v), qq) - v.begin();
		ll res = qq * (2 * pa[k] - pa[n]) + (pax[n] - 2 * pax[k]);

		cout << res << "\n";
	}

	return 0;
}