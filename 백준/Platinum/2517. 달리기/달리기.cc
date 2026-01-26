#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<int> v;
vector<int> tree;
map<int, int> mp;

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

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> tmp = v;
	sort(all(tmp));
	int idx = 0;
	for (int i = 0; i < tmp.size(); i++) {
		mp[tmp[i]] = ++idx;
	}

	// 좌표 압축
	for (int i = 0; i < n; i++) {
		v[i] = mp[v[i]];
	}

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	for (int i = 0; i < n; i++) {
		// 앞에 나보다 센 사람 수
		cout << query(1, 1, n, v[i] + 1, idx) + 1 << "\n"; 
		update(1, 1, n, v[i], 1);
	}

	return 0;
}