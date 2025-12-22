#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;

ll divide_pow(ll k, ll x, ll mod) {
	ull res = 1;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (!miller(n)) {
		cout << "no\n";
		exit(0);
	}

	string str_n = to_string(n);

	reverse(all(str_n));

	string rev = "";
	for (auto c : str_n) {
		if (c == '0' || c == '2' || c == '5' || c == '8' || c == '1') rev += c;
		else if (c == '6') rev += '9';
		else if (c == '9') rev += '6';
		else {
			cout << "no\n";
			exit(0);
		}
	}

	ll rev_n = stoll(rev);

	if (!miller(rev_n)) {
		cout << "no\n";
	}
	else cout << "yes\n";

	return 0;
}