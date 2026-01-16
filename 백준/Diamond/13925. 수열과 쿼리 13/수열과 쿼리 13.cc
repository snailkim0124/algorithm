#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1'000'000'007;
vector<ll> tree, add_lazy, mul_lazy;
vector<ll> a;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = a[s] % mod;
	else {
		int mid = (s + e) / 2;
		return tree[node] = (init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e)) % mod;
	}
}

// 느리게 갱신되는 세그트리
void propagate(int node, int s, int e) {
	if (add_lazy[node] != 0 || mul_lazy[node] != 1) {
		ll sz = e - s + 1;

		tree[node] = (tree[node] * mul_lazy[node]) % mod;
		tree[node] = (tree[node] + sz * add_lazy[node]) % mod;

		if (s != e) {
			mul_lazy[node * 2] = (mul_lazy[node * 2] * mul_lazy[node]) % mod;
			mul_lazy[node * 2 + 1] = (mul_lazy[node * 2 + 1] * mul_lazy[node]) % mod;

			add_lazy[node * 2] = (add_lazy[node * 2] * mul_lazy[node] + add_lazy[node]) % mod;
			add_lazy[node * 2 + 1] = (add_lazy[node * 2 + 1] * mul_lazy[node] + add_lazy[node]) % mod;
		}

		mul_lazy[node] = 1;
		add_lazy[node] = 0;
	}
}

void update(int node, int s, int e, int l, int r, ll add_val, ll mul_val) {
	propagate(node, s, e);

	if (l > e || r < s) return;
	if (l <= s && e <= r) {
		mul_lazy[node] = (mul_lazy[node] * mul_val) % mod;
		add_lazy[node] = (add_lazy[node] * mul_val + add_val) % mod;
		propagate(node, s, e);
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, l, r, add_val, mul_val);
	update(node * 2 + 1, mid + 1, e, l, r, add_val, mul_val);
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % mod;
}


ll query(int node, int s, int e, int l, int r) {
	propagate(node, s, e);

	if (l > e || r < s) return 0; // 범위 밖
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return (query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	add_lazy.resize(tree_size, 0);
	mul_lazy.resize(tree_size, 1);

	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	init(1, 1, n);

	int m;
	cin >> m;
	while (m--) {
		ll cmd, x, y, v;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x >> y >> v;
			update(1, 1, n, x, y, v, 1);
		}
		else if (cmd == 2) {
			cin >> x >> y >> v;
			update(1, 1, n, x, y, 0, v);
		}
		else if (cmd == 3) {
			cin >> x >> y >> v;
			update(1, 1, n, x, y, v, 0);
		}
		else if (cmd == 4) {
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << "\n";
		}
	}


	return 0;
}