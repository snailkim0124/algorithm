#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, c, q;
vector<ll> tree, lazy;
vector<ll> adj[200005];
ll l[200005], r[200005], depth[200005];
ll cnt = 0;

void dfs(ll now, ll prev, ll d) {
	l[now] = ++cnt;
	depth[now] = d;

	for (auto next : adj[now]) {
		if (next != prev) dfs(next, now, d + 1);
	}

	r[now] = cnt;
}

void propagate(int node, int s, int e) {
	if (lazy[node] != 0) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int l, int r, ll val) {
	propagate(node, s, e);

	if (l > e || r < s) return;
	if (l <= s && e <= r) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, l, r, val);
	update(node * 2 + 1, mid + 1, e, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	propagate(node, s, e);

	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(c, 0, 1);

	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : " << l[i] << " : " << depth[i] << "\n";
	//}

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	lazy.resize(tree_size);

	cin >> q;
	while (q--) {
		int cmd, a;
		cin >> cmd >> a;

		if (cmd == 1) {
			update(1, 1, n, l[a], l[a], 1);
		}
		else if (cmd == 2) {
			cout << query(1, 1, n, l[a], r[a]) * depth[a] << "\n";
		}
	}
	
	return 0;
}