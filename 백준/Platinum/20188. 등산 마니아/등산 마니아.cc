#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<ll> adj[300005];
ll res;

ll dfs(ll now, ll prev) {
	ll tmp = 1;

	for (auto next : adj[now]) {
		if (prev != next) {
			ll child = dfs(next, now);
			// 서로 다른 자식 2개 고를때 + 특정 간선 밑에 있는 자식, 아예 다른 간선
			res += child * (n - child) + child * (child - 1) / 2;
			tmp += child;
		}
	}

	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	cout << res;

	
	return 0;
}