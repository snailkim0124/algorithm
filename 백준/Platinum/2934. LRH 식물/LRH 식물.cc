#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll MAX = 100000;
vector<ll> tree, lazy;
vector<ll> v;

void propagate(int node, int s, int e) {
	if (lazy[node] != 0) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int l, int r, ll val) {
	propagate(node, s, e);
	if (l > e || r < s) return;
	if (l <= s && e <= r) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, l, r, val);
	update(node * 2 + 1, mid + 1, e, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	propagate(node, s, e);
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	tree.resize(MAX * 4 + 5);
	lazy.resize(MAX * 4 + 5);

	ll n;
	cin >> n;
	while (n--) {
		ll l, r;
		cin >> l >> r;
		ll left = query(1, 1, MAX, l, l);
		ll right = query(1, 1, MAX, r, r);
		cout << left + right << "\n";
		// 0으로 만들기
		update(1, 1, MAX, l, l, -left);
		update(1, 1, MAX, r, r, -right);

		// 각 모서리 제외한 구간 1씩 더하기
		update(1, 1, MAX, l + 1, r - 1, 1);
	}

	return 0;
}