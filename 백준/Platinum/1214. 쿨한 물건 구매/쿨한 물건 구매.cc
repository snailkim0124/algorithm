#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll d, p, q;
ll res = LLONG_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> d >> p >> q;
	if (p > q) swap(p, q);

	// 1. p만 한 경우
	ll cnt1 = 0;
	if (d % p == 0) {
		cnt1 = d / p;
	}
	else {
		cnt1 = d / p + 1;
	}

	res = min(res, p * cnt1);

	// 2. q만 한 경우
	ll cnt2 = 0;
	if (d % q == 0) {
		cnt2 = d / q;
	}	
	else {
		cnt2 = d / q + 1;
	}
	res = min(res, q * cnt2);

	if (res == d) {
		cout << d << "\n";
		exit(0);
	}

	// 완탐
	for (ll i = 0; i <= p; i++) {
		ll tmp = i * q;
		if (tmp >= d) {
			res = min(res, tmp);
			break;
		}

		// p로 채우기
		ll diff = d - tmp;
		tmp += ((int)ceil((double)diff / p) * p);

		res = min(res, tmp);
	}

	cout << res << "\n";
	
	

	return 0;
}