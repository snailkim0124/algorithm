#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, c;
int money[1005];
vector<int> adj[1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		cin >> money[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	memset(dp, -1, sizeof(dp));

	dp[0][1] = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != -1) {
				for (auto next : adj[j]) {
					dp[i + 1][next] = max(dp[i + 1][next], dp[i][j] + money[next]);
				}
			}
		}
	}

	int mx = 0;
	for (int i = 0; i <= 1000; i++) {
		if (dp[i][1] != -1) {
			mx = max(mx, dp[i][1] - c * i * i);
		}
	}
	cout << mx << "\n";


	return 0;
}