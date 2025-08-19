#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll arr[300005];
const ll mod = 1000000007;
ll ans;

ll divided_pow(ll n, ll k) {
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

	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		// i번째가 최대인 경우, i번째가 최소인 경우
		ll mx = divided_pow(2, i);
		ll mn = divided_pow(2, n - 1 - i);

		ans = (ans + (((mx - mn) % mod) * (arr[i] % mod)) % mod + mod) % mod;
	}
	
	cout << ans;

	return 0;
}