#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> tree[800005];
vector<ll> adj[200005];
vector<ll> l, r;
vector<ll> v, p, visited;
ll cnt;

void dfs(int now) {
	visited[now] = 1;
	l[now] = ++cnt;
	v[cnt] = p[now];

	for (auto next : adj[now]) {
		if (!visited[next]) dfs(next);
	}
	r[now] = cnt;
}

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

ll query(int node, int s, int e, int l, int r, int val) {
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) {
		// val보다 높은 숫자 세기
		return tree[node].end() - upper_bound(all(tree[node]), val);
	}
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r, val) + query(node * 2 + 1, mid + 1, e, l, r, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	p.resize(n + 1);
	v.resize(n + 1);
	l.resize(n + 1);
	r.resize(n + 1);
	visited.resize(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 2; i <= n; i++) {
		int parent;
		cin >> parent;
		adj[parent].push_back(i);
	}

	dfs(1); // 오일러 경로

	init(1, 1, n);

	for (int i = 1; i <= n; i++) {
		cout << query(1, 1, n, l[i], r[i], p[i]) << "\n";
	}

	return 0;
}