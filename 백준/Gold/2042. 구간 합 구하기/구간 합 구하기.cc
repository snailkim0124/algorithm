#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll init(vector<ll>& v, vector<ll>& tree, int node, int s, int e) {
	if (s == e) return tree[node] = v[s];
	else {
		return tree[node] = init(v, tree, node * 2, s, (s + e) / 2) + init(v, tree, node * 2 + 1, (s + e) / 2 + 1, e);
	}
}

void update(vector<ll>& tree, int node, int s, int e, int idx, ll diff) {
	if (idx < s || idx > e) return;
	tree[node] += diff;
	if (s != e) {
		update(tree, node * 2, s, (s + e) / 2, idx, diff);
		update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
	}
}

ll sum(vector<ll>& tree, int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) {
		return tree[node];
	}
	return sum(tree, node * 2, s, (s + e) / 2, l, r) + sum(tree, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> v(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> tree(tree_size);
	m += k;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	init(v, tree, 1, 0, n - 1);
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - v[b - 1];
			v[b - 1] = c;
			update(tree, 1, 0, n - 1, b - 1, diff);
		}
		else if (a == 2) {
			cout << sum(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	

	return 0;
}