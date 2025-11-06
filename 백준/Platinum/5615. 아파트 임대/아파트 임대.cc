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

bool miller(ll n) {
	if (n < 2) return false;

	for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n % p == 0) return n == p;
	}

	ull d = n - 1, s = 0;
	while ((d & 1) == 0) {
		d >>= 1;
		s++;
	}

	// 확률적으로 접근
	for (ull a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if (a % n == 0) continue;
		ull x = divide_pow(a, d, n);

		if (x == 1 || x == n - 1) continue;
		bool flag = true;
		for (int i = 1; i < s; i++) {
			x = (x * x) % n;
			if (x == n - 1) {
				flag = false;
				break;
			}
		}

		if (flag) return false;
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
		if (miller(2 * s + 1)) cnt++;
	}
	
	cout << cnt << "\n";

	return 0;
}