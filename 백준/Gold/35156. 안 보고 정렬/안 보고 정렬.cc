#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 998'244'353;

// 분할 정복 거듭제곱
ll divide_pow(ll k, ll x) {
	ll res = 1;
	k %= mod;
	while (x > 0) {
		if (x % 2 == 1) res = (res * k) % mod;
		k = (k * k) % mod;
		x /= 2;
	}
	return res % mod;
}

void solve() {
	ll n, l, r;
	cin >> n >> l >> r;

	if (l == r) {
		cout << 1 << "\n";
		return;
	}

	ll sz = r - l + 1;
	ll sum = divide_pow(sz, n); // 전체
	ll tmp1 = divide_pow(sz - 1, n); // 최소 < l
	ll tmp2 = divide_pow(sz - 1, n); // 최대 > r
	ll tmp3 = divide_pow(sz - 2, n); // l < 최소, 최대 < r

	sum = (sum - tmp1 + mod) % mod;
	sum = (sum - tmp2 + mod) % mod;
	sum = (sum + tmp3) % mod;

	cout << sum << "\n";
	
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