#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll a, x;
const ll mod = 1000000007;

ll divided_pow(ll n, ll k) {
	ll res = 1;
	while (k) {
		if (k % 2 == 1) res = (res * n) % mod;
		n = (n * n) % mod;
		k /= 2;
		res %= mod;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> x;
	a %= mod;
	cout << divided_pow(a, x) << "\n";

	return 0;
}