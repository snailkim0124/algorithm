#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1e9 + 7;
const ll MAX = 1e5;
ll n;
vector<ll> a;

void update(vector<ll>& tree, int node, int s, int e, int idx, ll val) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node] = (tree[node] + val) % mod;
		return;
	}

	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, idx, val);
	update(tree, node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % mod;
}

ll query(vector<ll>& tree, int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0; // 범위 밖
	if (l <= s && e <= r) return tree[node] % mod;

	int mid = (s + e) / 2;
	return (query(tree, node * 2, s, mid, l, r) + query(tree, node * 2 + 1, mid + 1, e, l, r)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	a.resize(n);

	vector<ll> tree[15];
	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	for (int i = 1; i <= 11; i++) {
		tree[i].resize(tree_size);
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		// 길이별
		for (int j = 1; j <= 11; j++) {
			if (j == 1) {
				update(tree[j], 1, 1, MAX, a[i], 1);
			}
			else {
				ll val = query(tree[j - 1], 1, 1, MAX, 1, a[i] - 1);
				update(tree[j], 1, 1, MAX, a[i], val);
			}
		}
	}

	cout << query(tree[11], 1, 1, MAX, 1, MAX) << "\n";
	
	return 0;
}