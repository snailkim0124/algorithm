#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int MAX = 2000000;
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

ll query(int node, int s, int e, ll x) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (tree[node * 2] >= x) return query(node * 2, s, mid, x);
	else return query(node * 2 + 1, mid + 1, e, x - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	while (n--) {
		ll q, x;
		cin >> q >> x;
		if (q == 1) {
			update(1, 1, MAX, x, 1);

		}
		else if (q == 2) {
			ll ans = query(1, 1, MAX, x);
			cout << ans << "\n";
			update(1, 1, MAX, ans, -1);
		}
	}

	return 0;
}