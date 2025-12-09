#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
vector<vector<ll>> tree;
vector<ll> v;
const ll mod = (ll)(1e9 + 7);

void update(int node, int s, int e, int idx, ll len, ll val) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[len][node] += val;
		tree[len][node] %= mod;
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, len, val);
	update(node * 2 + 1, mid + 1, e, idx, len, val);
	tree[len][node] = (tree[len][node * 2] + tree[len][node * 2 + 1]) % mod;
}

ll query(int node, int s, int e, int l, int r, ll len) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[len][node] % mod;
	int mid = (s + e) / 2;
	return (query(node * 2, s, mid, l, r, len) + query(node * 2 + 1, mid + 1, e, l, r, len)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	v.resize(n);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(k + 1, vector<ll>(tree_size, 0));

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		vector<ll> dp(k + 1, 0); // 길이
		dp[1] = 1;

		for (int j = 2; j <= k; j++) {
			dp[j] = query(1, 1, n, 1, v[i] - 1, j - 1);
		}
		
		// 길이에 따른 업데이트
		for (int j = 1; j <= k; j++) {
			if (dp[j]) {
				update(1, 1, n, v[i], j, dp[j]);
			}
		}
	}
	

	cout << query(1, 1, n, 1, n, k) << "\n";

	return 0;
}