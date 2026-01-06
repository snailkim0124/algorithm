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
vector<pii> adj[1005];
int deg[1005], dp[1005], memo[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({ q, r });

		if (q != 1) deg[q]++;
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto [next, cost] : adj[now]) {
			deg[next]--;
			if (dp[next] < dp[now] + cost) {
				dp[next] = dp[now] + cost;
				memo[next] = now;
			}

			if (deg[next] == 0) q.push(next);
		}
	}

	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";*/

	cout << dp[1] << "\n";

	vector<int> ans;
	ans.push_back(1); // 끝
	for (int now = memo[1]; now != 1; now = memo[now]) {
		ans.push_back(now);
	}
	ans.push_back(1); // 시작

	reverse(all(ans));
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << "\n";


	return 0;
}