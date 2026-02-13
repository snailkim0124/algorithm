#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
string s;
ll res;

ll go(ll y, ll x) {
	ll cnt = 0;
	ll sum = y + x;

	if (sum < n) {
		cnt = sum * (sum + 1) / 2;

		if (sum % 2 == 0) cnt += x + 1;
		else cnt += y + 1;
	}
	else {
		// 끝에서 역으로
		ll tmp = (2 * n - 2) - sum;
		ll val = n * n - tmp * (tmp + 1) / 2;

		if (sum % 2 == 0) cnt = val - (n - 1 - x);
		else cnt = val - (n - 1 - y);
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	cin >> s;

	ll y = 0, x = 0;
	res = 1;

	for (auto c : s) {
		if (c == 'U') y--;
		else if (c == 'D') y++;
		else if (c == 'L') x--;
		else if (c == 'R') x++;

		res += go(y, x);
	}

	cout << res << "\n";

	return 0;
}