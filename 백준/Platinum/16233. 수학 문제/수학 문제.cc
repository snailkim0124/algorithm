#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll one[10] = { 1, 11, 111,1111,11111,111111,1111111,11111111,111111111, 1111111111 };

void solve() {
	ll n;
	cin >> n;
	if (n % 9 != 0) {
		cout << -1 << " ";
		return;
	}
	n /= 9;

	ll ans = 0;
	for (int i = 9; i >= 0; i--) {
		ll q = n / one[i];

		if (q > 9) {
			cout << -1 << " ";
			return;
		}

		ans = ans * 10 + q;
		n %= one[i];
	}

	cout << ans * 10 << " ";
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