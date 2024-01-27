#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> tree;
vector<ll> a, b;
ll res;

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

	cin >> n;
	a.resize(1000005);
	b.resize(1000005);
	tree.resize(1000005);

	for (int i = 1; i <= n; i++) {
		ll num;
		cin >> num;
		a[num] = i;
		//update(i, a[i]);
	}

	for (int i = 1; i <= n; i++) {
		ll num;
		cin >> num;
		b[i] = a[num];
	}

	for (int i = 1; i <= n; i++) {
		update(b[i], 1);
		res += (i - sum(b[i]));
	}
	cout << res;

	return 0;
}