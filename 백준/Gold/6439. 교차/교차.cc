#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

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
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4;
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		pll p1, p2, s1, s2, s3, s4;
		ll sstartx, sstarty, sendx, sendy;
		cin >> p1.first >> p1.second >> p2.first >> p2.second;
		cin >> sstartx >> sstarty >> sendx >> sendy;

		s1 = { min(sstartx, sendx), min(sstarty, sendy) };
		s2 = { min(sstartx, sendx), max(sstarty, sendy) };
		s3 = { max(sstartx, sendx), min(sstarty, sendy) };
		s4 = { max(sstartx, sendx), max(sstarty, sendy) };

		if (iscross({ p1, p2 }, { s1, s2 }) || iscross({ p1, p2 }, { s1, s3 }) || iscross({ p1, p2 }, { s2, s4 }) || iscross({ p1,p2 }, { s3, s4 })) {
			cout << "T" << "\n";
		}
		else {
			if ((s1.first < p1.first && p1.first < s4.first && s1.first < p2.first && p2.first < s4.first) && (s1.second < p1.second && p1.second < s4.second && s1.second < p2.second && p2.second < s4.second)) {
				cout << "T" << "\n";
			}
			else cout << "F" << "\n";
		}
	}

	return 0;
}