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

void update(int node, int s, int e, int idx) {
	tree[node]--; // 모든 경로에 있는 거 없애기
	if (s == e) return;

	int mid = (s + e) / 2;
	if (idx <= mid) update(node * 2, s, mid, idx);
	else update(node * 2 + 1, mid + 1, e, idx);
}

ll query(int node, int s, int e, int val) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (tree[node * 2] >= val) return query(node * 2, s, mid, val);
	else return query(node * 2 + 1, mid + 1, e, val - tree[node * 2]);
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

	init(1, 1, n);

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		int idx = query(1, 1, n, num + 1);

		ans[idx] = i;
		update(1, 1, n, idx);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}