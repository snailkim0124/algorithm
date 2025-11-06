#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ull divide_pow(ull k, ull x, ull mod) {
	ull res = 1;
	while (x > 0) {
		if (x % 2 == 1) res = (res * k) % mod;
		k = (k * k) % mod;
		x /= 2;
	}

	return res;
}

bool miller(ull d, ull n, ull a) {
	ull x = divide_pow(a, d, n);

	if (x == 1 || x == n - 1) return true;
	while (d != n - 1) {
		x = (x * x) % n;
		d <<= 1;
		// 합성수
		if (x == 1) return false;
		// 소수일 수 있음
		if (x == n - 1) return true;
	}

	return false;
}

bool isprime(ll n) {
	if (n < 2) return false;

	for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n % p == 0) return n == p;
	}

	ull d = n - 1;
	while ((d & 1) == 0) d >>= 1;

	// 확률적으로 접근
	for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if (a % n == 0) continue;
		if (!miller(d, n, a)) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ull n, cnt = 0;
	cin >> n;
	while (n--) {
		ull s;
		cin >> s;
		// 2 * s + 1이 소수면 없음
		if (isprime(2 * s + 1)) cnt++;
	}
	
	cout << cnt << "\n";

	return 0;
}