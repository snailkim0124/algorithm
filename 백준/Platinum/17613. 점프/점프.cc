#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
vector<ll> v(32);

ll f(ll k) {
	if (k == 0) return 0;
	return (1LL << k) - 1;
}

ll go(ll num) {
	ll tmp = num + 1;

	ll cnt = 0;
	while (tmp > 1) {
		tmp >>= 1;
		cnt++;
	}

	return cnt;
}

ll solve(ll x, ll y) {
	ll res = 0;
	ll xcnt = go(x);
	ll ycnt = go(y);

	// 같은 구간인 경우
	if (xcnt == ycnt) {
		ll k = xcnt;
		ll tmpx = f(k);

		if (x == tmpx) {
			res = k;
		}

		ll nx = (x == tmpx) ? 1 : x - tmpx;
		ll ny = y - tmpx;

		if (nx <= ny) {
			res = max(res, k + solve(nx, ny));
		}
	}
	// 다른 구간인 경우
	else {
		res = 0;
		res = max(res, solve(x, f(xcnt + 1) - 1));

		for (int i = xcnt + 1; i < ycnt; i++) {
			res = max(res, i + v[i]);
		}

		res = max(res, solve(f(ycnt), y));
	}


	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 최대 점프 횟수
	v[1] = 1;
	for (int i = 2; i <= 30; i++) {
		v[i] = 1 + i * (i - 1) / 2;
	}

	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		cout << solve(x, y) << "\n";
	}


	return 0;
}