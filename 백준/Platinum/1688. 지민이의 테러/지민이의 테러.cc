#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<pll> v;

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

bool isinline(pll a, pll b, pll p) {
	return (ccw(a, b, p) == 0 && min(a.first, b.first) <= p.first && p.first <= max(a.first, b.first) && min(a.second, b.second) <= p.second && p.second <= max(a.second, b.second));
}

bool isinside(pll p) {
	ll cnt = 0;
	pll p1 = p;
	pll p2 = { 2e9, p.second }; 

	pair<pll, pll> tmp = { p1, p2 }; // 반직선

	for (int i = 0, j = n - 1; i < n; j = i++) {
		// 다각형 선분 훑기
		pll a = v[i];
		pll b = v[j];

		// 경계선에 있는지?
		if (isinline(a, b, p)) return true;

		if (iscross(tmp, { a, b })) {
			if(min(a.second, b.second) < p.second && p.second <= max(a.second, b.second)) cnt++;
		}
	}

	return cnt % 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < 3; i++) {
		pll num;
		cin >> num.first >> num.second;
		cout << isinside(num) << "\n";
	}

	return 0;
}