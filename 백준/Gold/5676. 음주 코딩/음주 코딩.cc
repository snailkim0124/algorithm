#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<ll> mtree, ztree;
vector<ll> mv, zv;

ll init(vector<ll> &tree, vector<ll> &v, int node, int s, int e) {
	if (s == e) return tree[node] = v[s];
	else {
		int mid = (s + e) / 2;
		return tree[node] = init(tree, v, node * 2, s, mid) + init(tree, v, node * 2 + 1, mid + 1, e);
	}
}

void update(vector<ll>& tree, int node, int s, int e, int idx, ll val) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node] = val;
		return;
	}

	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, idx, val);
	update(tree, node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(vector<ll>& tree, int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0; // 범위 밖
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, l, r) + query(tree, node * 2 + 1, mid + 1, e, l, r);
}

void solve() {
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	mtree.assign(tree_size, 0);
	ztree.assign(tree_size, 0);

	mv.assign(n + 1, 0);
	zv.assign(n + 1, 0);

	// 음수의 개수 세기, 0 개수 세기
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num < 0) mv[i] = 1;
		else if (num == 0) zv[i] = 1;
	}

	init(mtree, mv, 1, 1, n);
	init(ztree, zv, 1, 1, n);
	vector<char> ans;

	while (m--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'C') {
			int i, val;
			cin >> i >> val;
			if (val < 0) {
				mv[i] = 1;
				update(mtree, 1, 1, n, i, 1);
			}
			else {
				mv[i] = 0;
				update(mtree, 1, 1, n, i, 0);
			}

			if (val == 0) {
				zv[i] = 1;
				update(ztree, 1, 1, n, i, 1);
			}
			else {
				zv[i] = 0;
				update(ztree, 1, 1, n, i, 0);
			}
		}
		else if (cmd == 'P') {
			int i, j;
			cin >> i >> j;

			int resz = query(ztree, 1, 1, n, i, j);

			if (resz > 0) {
				ans.push_back('0');
			}
			else {
				int resm = query(mtree, 1, 1, n, i, j);
				if (resm % 2 == 0) ans.push_back('+');
				else ans.push_back('-');
			}
		}
	}

	for (auto it : ans) {
		cout << it;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while (cin >> n >> m) {
		solve();
	}

	return 0;
}