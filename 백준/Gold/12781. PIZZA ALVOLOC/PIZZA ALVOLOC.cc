#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pll v[5];

ll ccw(pll p1, pll p2, pll p3) {
	ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool iscross(pair<pll, pll> l1, pair<pll, pll> l2) {
	pll p1 = l1.first;
	pll p2 = l1.second;
	pll p3 = l2.first;
	pll p4 = l2.second;

	ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0) {
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4;
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cin >> v[i].first >> v[i].second;
	}
	if (ccw(v[0], v[1], v[2]) * ccw(v[0], v[1], v[3]) < 0) {
		cout << 1;
	}
	else cout << 0;


	return 0;
}