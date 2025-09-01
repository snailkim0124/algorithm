#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree;
vector<ll> v;

void update(int node, int s, int e, ll idx, ll val) {
	if (idx < s || idx > e) return;
	tree[node] += val;
	if (s == e) return;

	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);
}

ll query(int node, int s, int e, ll idx) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (tree[node * 2] >= idx) return query(node * 2, s, mid, idx);
	else return query(node * 2 + 1, mid + 1, e, idx - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	for (int i = 1; i <= n; i++) {
		update(1, 1, n, i, 1);
	}

	int idx = k;
	int sz = n; // 살아있는 사람

	cout << "<";
	for (int i = 0; i < n; i++) {
		ll ans = query(1, 1, n, idx);
		if (i == n - 1) cout << ans;
		else cout << ans << ", ";
		update(1, 1, n, ans, -1);
		idx += k - 1;
		sz--;

		if (sz == 0) break;
		if (idx > sz) idx = (idx - 1) % sz + 1;
	}
	cout << ">";

	return 0;
}