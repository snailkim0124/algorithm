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
int visited[5005], scc_id[5005];
vector<int> adj[5005], rev_adj[5005];
stack<int> st;
vector<vector<int>> res;

void dfs1(int now) {
	visited[now] = 1;
	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs1(next);
		}
	}
	st.push(now);
}

void dfs2(int now, int id) {
	visited[now] = 1;
	scc_id[now] = id;
	for (auto next : rev_adj[now]) {
		if (!visited[next]) {
			dfs2(next, id);
		}
	}
}

void solve() {
	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		adj[v].push_back(w);
		rev_adj[w].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs1(i);
	}

	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	while (!st.empty()) {
		int t = st.top();
		st.pop();
		if (!visited[t]) {
			dfs2(t, ++cnt);
		}
	}

	vector<int> check(cnt + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (auto next : adj[i]) {
			if (scc_id[i] != scc_id[next]) {
				check[scc_id[i]] = 1;
			}
		}
	}

	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (!check[scc_id[i]]) {
			res.push_back(i);
		}
	}

	sort(all(res));
	
	for (auto it : res) {
		cout << it << " ";
	}
	cout << "\n";

	memset(visited, 0, sizeof(visited));
	memset(scc_id, 0, sizeof(scc_id));
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		rev_adj[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n;
		if (!n) break;
		cin >> m;
		solve();
	}
	

	return 0;
}