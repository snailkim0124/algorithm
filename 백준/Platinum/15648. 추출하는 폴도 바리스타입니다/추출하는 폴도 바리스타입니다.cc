#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k, d;
vector<ll> tree(4 * 500005);
ll kmod[500005], dp[500005];

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
}

void update(int node, int l, int r, int idx, ll val) {
	if (l == r) {
		tree[node] = max(tree[node], val);
		return;
	}

	int mid = (l + r) / 2;
	if (idx <= mid) update(node * 2, l, mid, idx, val);
	else update(node * 2 + 1, mid + 1, r, idx, val);

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> d;

	ll res = 1;
	for (int i = 0; i < n; i++) {
		ll s;
		cin >> s;

		ll tmp = 0;
		// 나머지 k가 같을때
		tmp = max(tmp, kmod[s % k]);

		// +-d 사이일 때
		tmp = max(tmp, query(1, 1, 500000, max(1LL, s - d), min(500000LL, s + d)));

		
		dp[s] = tmp + 1; // 부분수열 누적
		kmod[s % k] = max(kmod[s % k], dp[s]);

		update(1, 1, 500000, s, dp[s]);

		res = max(res, dp[s]);
	}


	cout << res << "\n";
	

	return 0;
}