#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Node {
	ll sum, lmx, rmx, mx;
};

const ll INF = 987654321;
ll n, m;
vector<ll> a;
vector<Node> tree;

Node merge(Node l, Node r) {
	Node res;
	res.sum = l.sum + r.sum;
	res.lmx = max(l.lmx, l.sum + r.lmx);
	res.rmx = max(r.rmx, r.sum + l.rmx);
	res.mx = max({ l.mx, r.mx, l.rmx + r.lmx });

	return res;
}

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = { a[s], a[s], a[s], a[s] };
		return;
	}

	int mid = (s + e) / 2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);

	tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return { 0, -INF, -INF, -INF };
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	Node lnode = query(node * 2, s, mid, l, r);
	Node rnode = query(node * 2 + 1, mid + 1, e, l, r);
	return merge(lnode, rnode);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	a.resize(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	init(1, 1, n);

	cin >> m;
	while (m--) {
		ll i, j;
		cin >> i >> j;
		cout << query(1, 1, n, i, j).mx << "\n";
	}


	return 0;
}