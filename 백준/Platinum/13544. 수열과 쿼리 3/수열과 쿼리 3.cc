#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll arr[100005];
vector<ll> tree[400005];

void update(int node, int s, int e, int idx, int val) {
	if (idx < s || idx > e) return;
	tree[node].push_back(val);
	if (s == idx && idx == e) return;
	if (s != e) {
		update(node * 2, s, (s + e) / 2, idx, val);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);
	}
}

ll query(int node, int s, int e, int l, int r, int val) {
	if (l > e || r < s) {
		return 0;
	}
	if (l <= s && e <= r) {
		// val보다 큰 숫자 세기
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
	}
	return query(node * 2, s, (s + e) / 2, l, r, val) + query(node * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(1, 1, n, i, arr[i]);
	}

	for (int i = 0; i <= 400000; i++) {
		sort(tree[i].begin(), tree[i].end());
	}

	ll last_ans = 0;
	cin >> m;
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		a ^= last_ans; b ^= last_ans; c ^= last_ans;
		last_ans = query(1, 1, n, a, b, c);
		cout << last_ans << "\n";
	}

	return 0;
}