#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;

	ll g = gcd(x, y);
	ll tmpx = x / g;
	ll tmpy = y / g;

	ll q = n / (tmpx + tmpy);
	ll r = n % (tmpx + tmpy);

	if (r == 0) {
		// 답이 한군데
		cout << 1 << "\n";
		cout << q * tmpy << " " << x + y << "\n";
	}
	else {
		// 답이 두군데 (나머지 처리)
		cout << 2 << "\n";
		ll rem = (r * tmpy) / (tmpx + tmpy);
		ll pos1 = q * tmpy + rem;
		ll pos2 = pos1 + 1;

		ll val1 = (x + y) - abs(x * pos1 - y * (n - pos1));
		ll val2 = (x + y) - abs(x * pos2 - y * (n - pos2));


		cout << pos1 << " " << val1 << "\n";
		cout << pos2 << " " << val2 << "\n";
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