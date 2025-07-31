#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
vector<pll> v;
vector<ll> tree;
ll cnt;

void update(int node, int s, int e, int idx) {
	if (idx < s || idx > e) return;
	if (s == e) tree[node] += 1;
	if (s != e) {
		update(node * 2, s, (s + e) / 2, idx);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];

	return query(node * 2, s, (s + e) / 2, l, r) + query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());


	for (int i = 0; i < v.size(); i++) {
		cnt += query(1, 1, n, v[i].second + 1, n);
		update(1, 1, n, v[i].second);
	}
	
	cout << cnt;

	return 0;
}