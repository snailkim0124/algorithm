#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll k;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	set<ll> s;

	for (ll i = 1; i <= abs(k); i++) {
		if ((k * k) % i == 0) {
			// k^2의 약수
			ll tmp1 = i;
			ll tmp2 = (k * k) / i;

			s.insert(2 * k - (tmp1 + tmp2));
			s.insert(2 * k + (tmp1 + tmp2));
		}
	}

	for (auto it : s) {
		res += it;
	}

	cout << s.size() << " " << res << "\n";

	return 0;
}