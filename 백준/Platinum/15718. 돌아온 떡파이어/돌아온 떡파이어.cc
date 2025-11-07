#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

// 100007 == 97 * 1031
ll fact1[100], invfact1[100];
ll fact2[1050], invfact2[1050];

tll ext_gcd(ll a, ll b) {
	if (b == 0) return { a, 1, 0 };
	auto [g, x1, y1] = ext_gcd(b, a % b);
	return { g, y1, x1 - (a / b) * y1 };
}


// 모듈러 역원
ll modinv(ll a, ll mod) {
	auto [g, x, y] = ext_gcd(a, mod);
	if (g != 1) return -1; // 역원 없음
	x %= mod;
	if (x < 0) x += mod;
	return x;
}

ll crt(ll a1, ll m1, ll a2, ll m2) {
	ll g = gcd(m1, m2);
	if ((a2 - a1) % g != 0) return -1;

	ll lcm = m1 * m2 / g;
	ll t = ((a2 - a1) / g) % (m2 / g);

	t = (t * modinv(m1 / g, m2 / g)) % (m2 / g);

	ll x = (a1 + t * m1) % lcm;
	if (x < 0) x += lcm;

	return x;
}

/// ===== 경우의 수 계산 ===== ///


ll divide_pow(ll k, ll x, ll mod) {
	ll res = 1;
	while (x > 0) {
		if (x % 2 == 1) res = (res * k) % mod;
		k = (k * k) % mod;
		x /= 2;
	}

	return res;
}

// nCr
ll comb(ll n, ll r, ll mod, ll fact[], ll invfact[]) {
	if (r < 0 || r > n) return 0;
	return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}

// 모듈러 역원
ll mod_inv(ll n, ll mod) {
	return divide_pow(n, mod - 2, mod);
}

// 뤼카 정리
ll lucas(ll n, ll r, ll mod, ll fact[], ll invfact[]) {
	if (r == 0) return 1;
	// 각 자리수를 mod진법으로
	ll ni = n % mod;
	ll ri = r % mod;

	return (lucas(n / mod, r / mod, mod, fact, invfact) * comb(ni, ri, mod, fact, invfact)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// mod = 97;
	fact1[0] = 1;
	invfact1[0] = 1;
	for (int i = 1; i <= 97; i++) {
		fact1[i] = (fact1[i - 1] * i) % 97;
		invfact1[i] = mod_inv(fact1[i], 97);
	}

	// mod = 1031
	fact2[0] = 1;
	invfact2[0] = 1;
	for (int i = 1; i <= 1031; i++) {
		fact2[i] = (fact2[i - 1] * i) % 1031;
		invfact2[i] = mod_inv(fact2[i], 1031);
	}

	// n-1Cm-2
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;

		// 엣지 케이스
		if (m == 1) {
			if (n == 0) cout << 1 << "\n";
			else cout << 0 << "\n";
			continue;
		}

		if (m >= n + 2) {
			cout << 0 << "\n";
			continue;
		}

		ll r1 = lucas(n - 1, m - 2, 97, fact1, invfact1);
		ll r2 = lucas(n - 1, m - 2, 1031, fact2, invfact2);

		// crt로 합치기

		ll ans = crt(r1, 97, r2, 1031);
		if (ans < 0) ans = 0;
		cout << ans % 100007 << "\n";
	}

	return 0;
}