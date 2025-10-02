#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree[400005];
vector<ll> v;

void init(int node, int s, int e) {
	if (s == e) tree[node].push_back(v[s]);
	else {
		tree[node].resize(e - s + 1);
		int mid = (s + e) / 2;
		init(node * 2, s, mid);
		init(node * 2 + 1, mid + 1, e);
		merge(all(tree[node * 2]), all(tree[node * 2 + 1]), tree[node].begin());
	}
}

ll query(int node, int s, int e, int l, int r, int idx) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) {
		// idx번째 수 리턴
		return upper_bound(all(tree[node]), idx) - tree[node].begin();
	}
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r, idx) + query(node * 2 + 1, mid + 1, e, l, r, idx);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	init(1, 1, n);

	while (m--) {
		ll i, j, k;
		cin >> i >> j >> k;

		ll left = -1e9;
		ll right = 1e9;
		ll ans = 0;

		while (left <= right) {
			ll mid = (left + right) / 2;
			ll cnt = query(1, 1, n, i, j, mid);
			if (cnt >= k) {
				ans = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}

		cout << ans << "\n";
	}


	return 0;
}