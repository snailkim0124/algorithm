#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 998'244'353;
ll fact[2000005], invfact[2000005];
ll dp[1000005], catalan[1000005];

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

void solve() {
	ll n;
	cin >> n;
	
	if (dp[n] == 0) cout << -1 << "\n";
	else cout << dp[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 팩토리얼 전처리
	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		invfact[i] = mod_inv(fact[i]);
	}

	// 카탈란 전처리
	catalan[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		catalan[i] = comb(2 * i, i) * mod_inv(i + 1) % mod;
	}

	// dp 전처리
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		if ((i - 1) % 3 == 0) dp[i] = (dp[i] - catalan[(i - 1) / 3] + mod) % mod;
	}

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}