#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	double dist = sqrt(y - x);
	ll cnt = round(sqrt(y - x));

	if (x == y) cout << 0;
	else if (dist > cnt) cout << cnt * 2;
	else cout << cnt * 2 - 1;

	return 0;
}