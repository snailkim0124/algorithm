#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m;
ll n, k;
const ll mod = 1000000007;
ll tmp;
ll ans;
ll fact[1000005];

ll divide_pow(ll n, ll k) {
	ll res = 1;

	while (k) {
		if (k % 2 == 1) res = (res * n) % mod;
		n = (n * n) % mod;
		k /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 펙토리얼 이용
	fact[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	cin >> n >> k;

	ll a = fact[n];
	ll b = (fact[k] * fact[n - k]) % mod;

	// 페르마의 소정리
	ans = ((a % mod) * divide_pow(b, mod - 2) % mod) % mod;

	cout << ans << "\n";

	return 0;
}