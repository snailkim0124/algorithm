#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		double sdist = sqrt(y - x);
		ll cnt = round(sqrt(y - x));

		if (sdist > cnt) cout << cnt * 2 << "\n"; // 내림 적용
		else cout << cnt * 2 - 1 << "\n";
	}

	return 0;
}