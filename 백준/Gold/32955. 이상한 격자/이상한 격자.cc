#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, a, b, c, d;
vector<pll> v;
vector<ll> x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> a >> b >> c >> d;
	x.resize(n);
	y.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	sort(all(x));
	sort(all(y));

	ll xidx;
	if (a + b > 0) {
		xidx = (n * a) / (a + b);
	}
	ll px = x[min(xidx, n - 1)];

	ll yidx;
	if (c + d > 0) {
		yidx = (n * c) / (c + d);
	}
	ll py = y[min(yidx, n - 1)];

	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] >= px) res += (x[i] - px) * a;
		else res += (px - x[i]) * b;

		if (y[i] >= py) res += (y[i] - py) * c;
		else res += (py - y[i]) * d;
	}

	cout << res << "\n";

	return 0;
}