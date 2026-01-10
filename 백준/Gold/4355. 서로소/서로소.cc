#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n;
		if (!n) break;
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}

		ll res = n;
		for (ll i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				res -= res / i;
				while (n % i == 0) n /= i;
			}
		}

		if (n > 1) res -= res / n;
		cout << res << "\n";
	}
	
	return 0;
}