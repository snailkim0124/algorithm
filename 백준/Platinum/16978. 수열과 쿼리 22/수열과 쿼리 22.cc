#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll> tll;

vector<ll> tree;
vector<ll> a, ans;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = a[s];
	else {
		int mid = (s + e) / 2;
		return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
	}
}

void update(int node, int s, int e, int idx, ll val) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node] = val;
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return 0; // 범위 밖
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	init(1, 1, n);

	vector<pll> query1;
	vector<tll> query2;
	int cnt2 = 0;

	int m;
	cin >> m;

	while (m--) {
		ll cmd;
		cin >> cmd;

		if (cmd == 1) {
			ll i, v;
			cin >> i >> v;
			query1.push_back({ i, v });
		}
		else if (cmd == 2) {
			ll k, i, j;
			cin >> k >> i >> j;
			query2.push_back({ k, i, j, cnt2++ });
		}
	}

	ans.resize(cnt2 + 1, 0);
	sort(all(query2)); // k 오름차순으로 정렬

	//for (auto [k, i, j, idx] : query2) {
	//	cout << k << " : " << i << " : " << j << " : " << idx << "\n";
	//}

	int uidx = 0; // 업데이트 된 idx
	for (auto [k, i, j, idx] : query2) {
		// k까지 업데이트
		while (uidx < k) {
			auto [i, v] = query1[uidx];
			update(1, 1, n, i, v);
			uidx++;
		}
		ans[idx] = query(1, 1, n, i, j);
	}

	for (int i = 0; i < cnt2; i++) {
		cout << ans[i] << "\n";
	}


	return 0;
}