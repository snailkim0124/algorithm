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
ll fact[400005], invfact[400005];

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

// nCr
ll comb(ll n, ll r) {
	if (r < 0 || r > n) return 0;
	return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}

// 모듈러 역원
ll mod_inv(ll n) {
	return divide_pow(n, mod - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i <= 400000; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		invfact[i] = mod_inv(fact[i]);
	}

	ll m;
	cin >> m;

	ll sum = 0;
	for (int i = 3; i <= m; i++) {
		sum = (sum + comb(2 * i, i)) % mod;
	}

	cout << sum << "\n";

	
	return 0;
}