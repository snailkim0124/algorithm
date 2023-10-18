#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
const int mod = 1000000007;
ll tmp;
ll ans;

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

	cin >> n >> k;
	
	ll a = 1;
	ll b = 1;
	// 페르마의 소정리
	for (int i = n; i >= n - k + 1; i--) {
		a = (a * i) % mod;
	}
	for (int i = 1; i <= k; i++) {
		b = (b * i) % mod;
	}
	ans = ((a % mod) * divide_pow(b, mod - 2) % mod) % mod;

	cout << ans;
	return 0;
}