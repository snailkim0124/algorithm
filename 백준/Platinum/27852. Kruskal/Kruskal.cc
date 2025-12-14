#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll divide_pow(ll k, ll x, ll mod) {
	ll res = 1;
	while (x > 0) {
		if (x % 2 == 1) res = ((__int128)res * k) % mod;
		k = ((__int128)k * k) % mod;
		x /= 2;
	}

	return res;
}

bool miller(ll n) {
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	ll d = n - 1, s = 0;
	while ((d & 1) == 0) {
		d >>= 1;
		s++;
	}

	// 확률적으로 접근
	for (ll a : {2, 3, 5, 7, 11}) {
		if (a % n == 0) continue;
		ll x = divide_pow(a, d, n);

		if (x == 1 || x == n - 1) continue;
		bool flag = true;
		for (int i = 1; i < s; i++) {
			x = ((__int128)x * x) % n;
			if (x == n - 1) {
				flag = false;
				break;
			}
		}

		if (flag) return false;
	}

	return true;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);

	// 소수 개수 전처리
	int primecnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (miller(a[i])) primecnt++;
	}

	// 소수인 더미 개수가 1보다 크면 바로 이김
	if (n > 1 && primecnt >= 1) {
		cout << "YES\n";
		return;
	}

	bool flag = false;

	// 님 게임
	ll x = 0;
	for (auto it : a) {
		ll tmp = it - 1;
		while (tmp >= 2 && !miller(tmp)) {
			tmp--;
		}

		// k 이하 되면 이김
		if (it - tmp <= k) {
			cout << "YES\n";
			return;
		}

		x ^= ((it - tmp) % (k + 1));
	}

	if (x == 0) cout << "NO\n";
	else cout << "YES\n";
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