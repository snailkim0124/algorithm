#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	res = n;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res -= res / i;
			while (n % i == 0) n /= i;
		}
	}

	if (n > 1) res -= res / n;
	cout << res;

	return 0;
}