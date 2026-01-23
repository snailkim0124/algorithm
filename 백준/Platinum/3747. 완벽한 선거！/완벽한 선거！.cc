#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<int> adj[2005], rev_adj[2005];
int visited[2005];
stack<int> st;
int scc_idx[2005];

void dfs1(int now) {
	visited[now] = 1;
	for (auto next : adj[now]) {
		if (!visited[next]) dfs1(next);
	}
	st.push(now);
}

void dfs2(int now, int idx) {
	visited[now] = 1;
	scc_idx[now] = idx;
	for (auto next : rev_adj[now]) {
		if (!visited[next]) dfs2(next, idx);
	}
}

int neg(int x) {
	return x > n ? x - n : x + n;
}

void solve() {
	for (int i = 1; i <= 2 * n + 1; i++) {
		adj[i].clear();
		rev_adj[i].clear();
	}
	memset(visited, 0, sizeof(visited));
	memset(scc_idx, 0, sizeof(scc_idx));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;

		adj[neg(a)].push_back(b);
		adj[neg(b)].push_back(a);

		rev_adj[b].push_back(neg(a));
		rev_adj[a].push_back(neg(b));
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (!visited[i]) dfs1(i);
	}

	memset(visited, 0, sizeof(visited));

	int idx = 0;
	while (!st.empty()) {
		int t = st.top();
		st.pop();

		if (!visited[t]) {
			dfs2(t, ++idx);
		}
	}


	for (int i = 1; i <= n; i++) {
		if (scc_idx[i] == scc_idx[i + n]) {
			cout << 0 << "\n";
			return;
		}
	}

	cout << 1 << "\n";


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n >> m) {
		solve();
	}
	

	return 0;
}