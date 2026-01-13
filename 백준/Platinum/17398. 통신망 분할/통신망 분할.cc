#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, q;
ll parent[100005], sz[100005], visited[100005];
vector<pll> edge;

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);

	parent[b] = a;
	sz[a] += sz[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> q;
	edge.resize(m + 1);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		edge[i] = { x, y };
	}

	// 오프라인 쿼리(거꾸로)
	stack<pii> st;
	ll res = 0;

	while (q--) {
		int a;
		cin >> a;
		st.push(edge[a]);
		visited[a] = 1;
	}

	// 삭제안되는 건 미리 연결
	for (int i = 1; i <= m; i++) {
		if (!visited[i]) {
			unionParent(edge[i].first, edge[i].second);
		}
	}

	while (!st.empty()) {
		auto [x, y] = st.top();
		st.pop();

		// 부모가 다를때만 비용
		if (findParent(x) != findParent(y)) {
			res += sz[findParent(x)] * sz[findParent(y)];
			unionParent(x, y);
		}
	}

	cout << res << "\n";

	return 0;
}