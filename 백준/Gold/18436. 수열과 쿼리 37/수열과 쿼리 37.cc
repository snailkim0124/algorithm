#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree;
vector<ll> a;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = a[s];
	else {
		int mid = (s + e) / 2;
		return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
	}
}

void update(int node, int s, int e, int idx, ll val) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node] = val;
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0; // 범위 밖
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	a.resize(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= 2;
	}

	init(1, 1, n);

	int m;
	cin >> m;
	while (m--) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll i, x;
			cin >> i >> x;
			update(1, 1, n, i, x % 2);
		}
		else if (cmd == 2) {
			ll l, r;
			cin >> l >> r;
			ll sz = r - l + 1;
			cout << sz - query(1, 1, n, l, r) << "\n";
		}
		else if (cmd == 3) {
			ll l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << "\n";
		}
	}

	return 0;
}