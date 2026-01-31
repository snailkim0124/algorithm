#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	ll total = (2 * n + 1) * (2 * n + 1);
	ll minus = 0;

	if (2 * n < k) {
		cout << total << "\n";
		exit(0);
	}
	else {
		ll tmp = (k + 1) / 2;
		if (tmp <= n) {
			ll cnt = n - tmp + 1;
			ll a = 2 * tmp - k + 1;
			ll b = 2 * n - k + 1;

			minus += (a + b) * cnt;
		}

		if (k % 2 == 0) {
			minus += (2 * tmp - 1);
		}
	}
	
	cout << total - minus << "\n";

	return 0;
}