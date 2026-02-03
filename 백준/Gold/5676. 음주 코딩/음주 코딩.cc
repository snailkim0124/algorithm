#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<ll> tree;
vector<ll> v;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = v[s];
	else {
		int mid = (s + e) / 2;
		return tree[node] = init(node * 2, s, mid) * init(node * 2 + 1, mid + 1, e);
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
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 1; // 범위 밖
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) * query(node * 2 + 1, mid + 1, e, l, r);
}

void solve() {
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.assign(tree_size, 0);

	v.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num < 0) v[i] = -1;
		else if (num == 0) v[i] = 0;
		else v[i] = 1;
	}

	init(1, 1, n);
	vector<char> ans;

	while (m--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'C') {
			int i, val;
			cin >> i >> val;
			if (val > 0) v[i] = 1;
			else if (val == 0) v[i] = 0;
			else v[i] = -1;

			update(1, 1, n, i, v[i]);
		}
		else if (cmd == 'P') {
			int i, j;
			cin >> i >> j;
			int res = query(1, 1, n, i, j);
			if (res > 0) ans.push_back('+');
			else if (res == 0) ans.push_back('0');
			else ans.push_back('-');
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