#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll arr[100005];
vector<pll> min_tree;

void init(int node, int s, int e) {
	if (s == e) {
		min_tree[node] = { arr[s], s };
	}
	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (idx < s || idx > e) return;
	if (s == idx && idx == e) {
		min_tree[node] = make_pair(val, idx);
	}
	if (s != e) {
		update(node * 2, s, (s + e) / 2, idx, val);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	}
}

pll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return make_pair(INT_MAX, INT_MAX);
	}
	if (l <= s && e <= r) {
		return min_tree[node];
	}
	return min(query(node * 2, s, (s + e) / 2, l, r), query(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	min_tree.resize(tree_size);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);

	cin >> m;
	while (m--) {
		ll q, a, b;
		cin >> q >> a >> b;

		if (q == 1) {
			update(1, 1, n, a, b);
		}
		else if (q == 2) {
			cout << query(1, 1, n, a, b).second << "\n";
		}
	}



	return 0;
}