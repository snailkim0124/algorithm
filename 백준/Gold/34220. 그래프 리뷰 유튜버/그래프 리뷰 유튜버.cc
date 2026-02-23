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
vector<int> adj[100005];
vector<pii> ans;
vector<int> candi;
map<pii, int> mp;

void dfs(int now, int prev) {
	if (candi.size() == 4) return;
	candi.push_back(now);
	if (candi.size() == 4) return;
	for (auto next : adj[now]) {
		if (prev != next) {
			dfs(next, now);

			if (candi.size() == 4) return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mp[{u, v}]++;
		mp[{v, u}]++;
	}

	int s = -1;
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		if (mx < (int)adj[i].size()) {
			mx = (int)adj[i].size();
			s = i;
		}
	}

	dfs(s, -1);

	for (int i = 0; i < candi.size(); i++) {
		for (int j = i + 1; j < candi.size(); j++) {
			if (!mp[{candi[i], candi[j]}] && !mp[{candi[j], candi[i]}]) {
				mp[{candi[i], candi[j]}]++;
				mp[{candi[j], candi[i]}]++;

				ans.push_back({ candi[i], candi[j] });
			}
		}
	}

	cout << ans.size() << "\n"; // 무조건 답은 3
	for (auto [u, v] : ans) {
		cout << u << " " << v << "\n";
	}

	
	return 0;
}