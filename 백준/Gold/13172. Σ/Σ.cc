#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m;
ll a, b;
const ll mod = 1000000007;
ll tmp;
ll ans;

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	else return gcd(y, x % y);
}

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

	cin >> m;
	while (m--) {
		cin >> a >> b;

		// 페르마의 소정리
		ans += b * divide_pow(a, mod - 2) % mod;
		ans %= mod;
	}

	cout << ans;
	
	return 0;
}