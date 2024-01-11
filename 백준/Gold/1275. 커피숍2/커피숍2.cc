#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, q;
vector<ll> tree;
vector<ll> v;

ll sum(ll idx) { // 합 구하기
	ll res = 0;
	while (idx > 0) {
		res += tree[idx];
		idx -= (idx & -idx);
	}

	return res;
}

void update(ll idx, ll diff) { // tree 업데이트
	while (idx < tree.size()) {
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	v.resize(n + 1);
	tree.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		update(i, v[i]);
	}

	for (int i = 0; i < q; i++) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x < y) {
			cout << sum(y) - sum(x - 1) << "\n";
		}
		else {
			cout << sum(x) - sum(y - 1) << "\n";
		}

		ll diff = b - v[a];
		v[a] = b;
		update(a, diff);
	}

	return 0;
}