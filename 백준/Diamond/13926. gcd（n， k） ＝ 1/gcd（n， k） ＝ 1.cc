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

	for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n % p == 0) return n == p;
	}

	ll d = n - 1, s = 0;
	while ((d & 1) == 0) {
		d >>= 1;
		s++;
	}

	// 확률적으로 접근
	for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
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

ll f(ll x, ll c, ll mod) {
	x = ((__int128)x * x) % mod;
	return (x + c) % mod;
}

ll pollard(ll n) {
	if (n % 2 == 0) return 2;
	ll x = rand() % n;
	ll y = x;
	ll c = rand() % n;
	if (c == 0) c = 1;

	ll d = 1;
	while (d == 1) {
		x = f(x, c, n);
		y = f(f(y, c, n), c, n);

		// f(x)와 f(f(y))의 차를 취하면 약수를 얻을 확률이 올라감
		d = gcd(abs(x - y), n);

		if (d == n) return pollard(n);
	}

	return d;
}

vector<ll> factor(ll n) {
	if (n == 1) return {};
	if (miller(n)) return { n };

	ll d = pollard(n);
	// 분할
	auto lv = factor(d);
	auto rv = factor(n / d);

	lv.insert(lv.end(), all(rv));

	return lv;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	vector<ll> fv = factor(n);

	sort(all(fv));
	// 중복 소인수제거
	fv.erase(unique(all(fv)), fv.end());
	
	// 오일러 피
	ll res = n;
	for (auto it : fv) {
		res -= res / it;
	}

	cout << res << "\n";

	return 0;
}