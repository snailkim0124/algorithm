#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree;
vector<ll> v, ans;

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = 1;
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

	v.resize(n + 1);
	ans.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	init(1, 1, n);

	// 역순으로 쓴거는 없애기
	for (int i = n; i >= 1; i--) {
		int tmp = query(1, 1, n, 1, n) - v[i]; // 순서 찾기

		int left = 1;
		int right = n;
		int idx = 0;

		while (left <= right) {
			int mid = (left + right) / 2;
			
			if (query(1, 1, n, 1, mid) >= tmp) {
				idx = mid;
				right = mid - 1;
			}
			else left = mid + 1;
		}

		ans[idx] = i;
		update(1, 1, n, idx, 0);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}