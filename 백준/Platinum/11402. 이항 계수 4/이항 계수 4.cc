#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll mod;
ll fact[2005], invfact[2005];

ll divide_pow(ll k, ll x) {
	ll res = 1;
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

// 뤼카 정리
ll lucas(ll n, ll r) {
	if (r == 0) return 1;
	// 각 자리수를 mod진법으로
	ll ni = n % mod;
	ll ri = r % mod;

	return (lucas(n / mod, r / mod) * comb(ni, ri)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, k;
	cin >> n >> k >> mod;

	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i <= mod; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		invfact[i] = mod_inv(fact[i]);
	}

	cout << lucas(n, k) << "\n";

	return 0;
}