#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1000000007;
ll n, sum;

ll divide_pow(ll k, ll x) {
	ll res = 1;
	while (x > 0) {
		if (x % 2 == 1) res = (res * k) % mod;
		k = (k * k) % mod;
		x /= 2;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		ll c, k;
		cin >> c >> k;

		ll multi = (c * k % mod);
		if (k >= 1) multi *= divide_pow(2, k - 1) % mod;

		sum = (sum + multi) % mod;
	}

	cout << sum << "\n";

	return 0;
}