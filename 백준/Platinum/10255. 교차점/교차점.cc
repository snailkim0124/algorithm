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

// 꼭짓점
bool iscross_point(pair<pll, pll> l1, pair<pll, pll> l2) {
	pll p1 = l1.first;
	pll p2 = l1.second;
	pll p3 = l2.first;
	pll p4 = l2.second;

	ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	return p1p2 == 0 && p3p4 <= 0;
}

// 선
bool iscross_line(pair<pll, pll> l1, pair<pll, pll> l2) {
	pll p1 = l1.first;
	pll p2 = l1.second;
	pll p3 = l2.first;
	pll p4 = l2.second;

	ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	return p1p2 < 0 && p3p4 <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int cnt = 0;
		pll p1, p2;
		pll s[5];
		ll xmin, ymin, xmax, ymax;
		cin >> xmin >> ymin >> xmax >> ymax;
		cin >> p1.first >> p1.second >> p2.first >> p2.second;
		if (p1 > p2) swap(p1, p2);

		s[0] = { xmin, ymin };
		s[1] = { xmin, ymax };
		s[2] = { xmax, ymin };
		s[3] = { xmax, ymax };

		// 겹침
		if (iscross({ p1, p2 }, { s[0], s[1] }) || iscross({ p1, p2 }, { s[0], s[2] }) || iscross({ p1, p2 }, { s[1], s[3] }) || iscross({ p1, p2 }, { s[2], s[3] })) {
			if (p1.first == p2.first && p1.second != p2.second) { // x = p1.first
				// 교점이 무한히 많은 경우(선이 겹침)
				if (xmin == p1.first || xmax == p1.first) {
					if ((ymin < p1.second && p2.second < ymax) || (ymin < p2.second && p1.second < ymax)) {
						cout << 4 << "\n";
					}
					else {
						cout << 1 << "\n";
					}
				}
				// 교점이 1개 또는 2개
				else {
					// 교점이 2개 (사각형이 사이에 있음)
					if (p1.second < ymin && ymax < p2.second) {
						cout << 2 << "\n";
					}
					else {
						cout << 1 << "\n";
					}
				}
			}
			else if (p1.first != p2.first && p1.second == p2.second) { // y = p1.second
				// 교점이 무한히 많은 경우(선이 겹침)
				if (ymin == p1.second || ymax == p1.second) {
					if ((xmin < p1.first && p2.first < xmax) || (xmin < p2.first && p1.first < xmax)) {
						cout << 4 << "\n";
					}
					else {
						cout << 1 << "\n";
					}
				}
				// 교점이 1개 또는 2개
				else {
					// 교점이 2개 (사각형이 사이에 있음)
					if (p1.first < xmin && xmax < p2.first) {
						cout << 2 << "\n";
					}
					else {
						cout << 1 << "\n";
					}
				}
			}
			else { // 사선
				// 선에 겹치는 개수 + 교점에 겹치는 개수 / 2;
				int cnt_line = 0;
				int cnt_point = 0;

				if (iscross_line({ p1, p2 }, { s[0], s[1] })) {
					cnt_line++;
				}
				if (iscross_line({ p1, p2 }, { s[0], s[2] })) {
					cnt_line++;
				}
				if (iscross_line({ p1, p2 }, { s[1], s[3] })) {
					cnt_line++;
				}
				if (iscross_line({ p1, p2 }, { s[2], s[3] })) {
					cnt_line++;
				}

				if (iscross_point({ p1, p2 }, { s[0], s[1] })) {
					cnt_point++;
				}
				if (iscross_point({ p1, p2 }, { s[0], s[2] })) {
					cnt_point++;
				}
				if (iscross_point({ p1, p2 }, { s[1], s[3] })) {
					cnt_point++;
				}
				if (iscross_point({ p1, p2 }, { s[2], s[3] })) {
					cnt_point++;
				}

				cout << cnt_line + cnt_point / 2 << "\n";
			}
		}
		// 안 겹침
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}