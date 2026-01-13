#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree, arr;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = arr[s];
	}
	else {
		init(node * 2, s, (s + e) / 2);
		init(node * 2 + 1, (s + e) / 2 + 1, e);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return INT_MIN;
	}
	if (l <= s && e <= r) {
		return tree[node];
	}
	return max(query(node * 2, s, (s + e) / 2, l, r), query(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	init(1, 1, n);

	for (int now = m; now <= n - m + 1; now++) {
		int l = now - (m - 1);
		int r = now + (m - 1);

		cout << query(1, 1, n, l, r) << " ";
	}
	cout << "\n";
	

	return 0;
}