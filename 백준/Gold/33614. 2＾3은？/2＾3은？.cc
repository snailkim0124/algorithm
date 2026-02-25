#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1'000'000'007;

void solve() {
	ll p, q, r;
	cin >> p >> q >> r;
	ll cnt = 0;
	
	// a == 1
		// b == c
	cnt = (cnt + min(q, r)) % mod;
	
	// b == 1
		// c == 1
	cnt = (cnt + (p - 1)) % mod;

	cout << cnt << "\n";
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