#include <bits/stdc++.h>
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
		merge(tree[node * 2].begin(), tree[node *2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
	}
}

ll query(int node, int s, int e, int l, int r, int val) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) {
		// val보다 큰 숫자 세기
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
	}
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r, val) + query(node * 2 + 1, mid + 1, e, l, r, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;

	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	init(1, 1, n);

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