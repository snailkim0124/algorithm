#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll arr[100005];
vector<ll> min_tree, max_tree;

void init(int node, int s, int e) {
	if (s == e) {
		min_tree[node] = max_tree[node] = arr[s]; 
	}
	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	}
}

void update(int node, int s, int e, int idx) {
	if (idx < s || idx > e) return;
	if (s == idx && idx == e) {
		min_tree[node] = max_tree[node] = arr[s];
	}
	if (s != e) {
		update(node * 2, s, (s + e) / 2, idx);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx);
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
	}
}

pll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return make_pair(INT_MAX, 0);
	}
	if (l <= s && e <= r) {
		return make_pair(min_tree[node], max_tree[node]);
	}

	pll lp = query(node * 2, s, (s + e) / 2, l, r);
	pll rp = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return make_pair(min(lp.first, rp.first), max(lp.second, rp.second));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		int n, k;
		cin >> n >> k;

		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		min_tree.resize(tree_size);
		max_tree.resize(tree_size);

		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}

		init(1, 0, n - 1);

		while (k--) {
			ll q, a, b;
			cin >> q >> a >> b;

			if (q == 0) {
				swap(arr[a], arr[b]);
				update(1, 0, n - 1, a);
				update(1, 0, n - 1, b);
			}
			else if (q == 1) {
				pll res = query(1, 0, n - 1, a, b);
				cout << (res == make_pair(a, b) ? "YES\n" : "NO\n");
			}
		}
	}



	return 0;
}