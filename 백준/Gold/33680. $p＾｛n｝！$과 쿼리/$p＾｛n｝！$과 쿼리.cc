#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1e9 + 7;

// 분할 정복 거듭제곱
ll divide_pow(ll k, ll x) {
	ll res = 1;
	k %= mod;
	while (x > 0) {
		if (x % 2 == 1) res = (res * k) % mod;
		k = (k * k) % mod;
		x /= 2;
	}
	return res;
}

// 모듈러 역원
ll mod_inv(ll n) {
	return divide_pow(n, mod - 2);
}


void solve() {
	ll p, n;
	cin >> p >> n;

	cout << (((divide_pow(p, n) - 1 + mod) % mod) * (mod_inv((p - 1 + mod) % mod))) % mod << "\n";

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