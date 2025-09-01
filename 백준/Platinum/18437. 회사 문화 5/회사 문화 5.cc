#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree, lazy;
vector<ll> adj[100005];
vector<ll> l, r;
ll cnt;

void dfs(int now) {
	l[now] = ++cnt;
	for (auto next : adj[now]) {
		dfs(next);
	}

	r[now] = cnt - 1;
}

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = 1;
	else {
		int mid = (s + e) / 2;
		return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
	}
}

// 느리게 갱신되는 세그트리
void propagate(int node, int s, int e) {
	if (lazy[node] != -1) {
		tree[node] = (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update(int node, int s, int e, int l, int r, ll val) {
	propagate(node, s, e);

	if (l > e || r < s) return;
	if (l <= s && e <= r) {
		lazy[node] = val;
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

	if (l > e || r < s) return 0; // 범위 밖
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	lazy.resize(tree_size, -1);

	l.resize(n + 1);
	r.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int parent;
		cin >> parent;
		adj[parent].push_back(i);
	}

	init(1, 1, n); // 컴퓨터 처음에 켜짐

	dfs(0); // 직속 부하 찾기

	cin >> m;
	while (m--) {
		ll q, i;
		cin >> q >> i;
		if (q == 1) {
			update(1, 1, n, l[i], r[i], 1);
		}
		else if (q == 2) {
			update(1, 1, n, l[i], r[i], 0);
		}
		else if (q == 3) {
			cout << query(1, 1, n, l[i], r[i]) << "\n";
		}
	}


	return 0;
}