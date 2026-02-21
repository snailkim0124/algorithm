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
vector<ll> adj[200005];
ll dp[200005], sz[200005];

void dfs(int now) {
	dp[now] = 1;
	sz[now] = 1;

	for (auto next : adj[now]) {
		dfs(next);

		sz[now] += sz[next];
		dp[now] += dp[next] + sz[next];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		ll num;
		cin >> num;
		adj[num].push_back(i);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";


	return 0;
}