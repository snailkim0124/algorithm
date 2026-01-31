#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll go(ll n, ll k) {
	if (k <= (n + 1) / 2) {
		return 2 * k - 1;
	}

	ll tmp = go(n / 2, k - (n + 1) / 2);
	//cout << n << " : " << k << " : " << tmp << "\n";

	if (n % 2 == 0) {
		return tmp * 2;
	}
	else {
		// 마지막일 때
		if (tmp == n / 2) {
			return 2;
		}

		return (tmp + 1) * 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, k;
	cin >> n >> k;
	
	cout << go(n, k) << "\n";

	return 0;
}