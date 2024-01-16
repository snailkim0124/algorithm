#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int parent[3005];
pair<pll, pll> v[3005];
int counting[3005];
int group, cnt;

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v[i] = {{x1, y1} , {x2, y2}};
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (iscross({ v[i].first, v[i].second }, { v[j].first , v[j].second })) {
				unionParent(i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		counting[findParent(i)]++;
	}

	for (int i = 1; i <= n; i++) {
		if (counting[i]) group++;
		cnt = max(cnt, counting[i]);
	}

	cout << group << "\n" << cnt;

	return 0;
}