#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t;
ll n, k;
const ll mod = 1000000007;
ll tmp;
ll ans;
ll fact[4000005];

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

	cin >> t;
	while (t--) {
		cin >> n;
		
		cout << divide_pow(2, n - 2) << "\n";
	}

	return 0;
}